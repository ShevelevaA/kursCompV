#include "DescriptorOperations.h"

vector<DMatch> DescriptorOperations::match(Mat descriptorsFirst, Mat descriptorsSecond)
{
	BFMatcher bf = BFMatcher(NORM_HAMMING, true);
	vector< DMatch > matches;
	bf.match(descriptorsFirst, descriptorsSecond, matches);
	return matches;
}

double DescriptorOperations::distanceByDescriptorIndex(vector<DMatch> match, int descriptorIndex)
{
	for (int i = 0; i < match.size(); i++)
		if (match[i].queryIdx == descriptorIndex)
			return match[i].distance;
	return maxDistance;
}

DescriptorCompare DescriptorOperations::compareDescriptors(ImageOPtions imageOrig, ImageOPtions imageFirst, ImageOPtions imageSecond, string commonModif)
{
	DescriptorCompare d;
	d.modif = commonModif;
	d.modif1 = imageFirst.getModidfication();
	d.modif2 = imageSecond.getModidfication();
	d.origDescrCount = imageOrig.getDescriptors().rows;
	vector<DMatch> matchIntensity = DescriptorOperations::match(imageOrig.getDescriptors(), imageFirst.getDescriptors());
	vector<DMatch> matchIntensity2 = DescriptorOperations::match(imageOrig.getDescriptors(), imageSecond.getDescriptors());
	const int maxDist = DescriptorOperations::maxDistance;
	for (int i = 0; i < imageOrig.getDescriptors().rows; i++) {
		double distanceIntensity = DescriptorOperations::distanceByDescriptorIndex(matchIntensity, i);
		double distanceIntensity2 = DescriptorOperations::distanceByDescriptorIndex(matchIntensity2, i);
		if (distanceIntensity == maxDist && distanceIntensity2 == maxDist) {
			d.difDistance.push_back(2 * maxDist);
			d.countNotFindAll++;
		}
		else
			if (distanceIntensity == maxDist) {
				d.difDistance.push_back(maxDist);
				d.countNotFindInt++;
			}
			else
				if (distanceIntensity2 == maxDist) {
					d.difDistance.push_back(0 - maxDist);
					d.countNotFindInt2++;
				}
				else {
					double diff = distanceIntensity - distanceIntensity2;
					d.difDistance.push_back(diff);
					d.distFindAll += abs(diff);
					if (diff < 0)
						d.countFindAllInt++;
					else
						if (diff > 0)
							d.countFindAllInt2++;
						else
							d.countFindAllMatch++;
				}
	}
	return d;
}
