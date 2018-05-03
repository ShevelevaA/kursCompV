#pragma once
#include "ImageOPtions.h"
#include "opencv\cv.h"
#include "opencv2\features2d\features2d.hpp"
#include "DescriptorCompare.h"

using namespace std;
using namespace cv;

class DescriptorOperations
{
public:
	static const int maxDistance = 100000;
	static vector<DMatch> DescriptorOperations::match(Mat descriptorsFirst, Mat descriptorsSecond);
	static double distanceByDescriptorIndex(vector<DMatch> match, int descriptorIndex);
	static DescriptorCompare compareDescriptors(ImageOPtions imageOrig, ImageOPtions imageFirst, ImageOPtions imageSecond, string commonModif);
};

