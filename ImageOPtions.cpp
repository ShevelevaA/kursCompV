#include "ImageOPtions.h"

ImageOPtions::~ImageOPtions()
{
}

void ImageOPtions::calculateKeyPoints()
{
	Ptr<FeatureDetector> detector = ORB::create(200);
	detector->detect(image, keyPoints);
}

void ImageOPtions::calculateDescriptors()
{
	Ptr<DescriptorExtractor> extractor = ORB::create();
	extractor->compute(image, keyPoints, descriptors);
}

ImageOPtions::ImageOPtions()
{
}

ImageOPtions::ImageOPtions(string pathInput, string modificationInput)
{
	modification = modificationInput;
	path = pathInput;
	image = imread(pathInput, CV_LOAD_IMAGE_GRAYSCALE);
	calculateKeyPoints();
	calculateDescriptors();
}

string ImageOPtions::getPathToImage()
{
	return path;
}

string ImageOPtions::getModidfication()
{
	return modification;
}

Mat ImageOPtions::getImage()
{
	return image;
}

vector<KeyPoint> ImageOPtions::getKeyPoints()
{
	return keyPoints;
}

Mat ImageOPtions::getDescriptors()
{
	return descriptors;
}
