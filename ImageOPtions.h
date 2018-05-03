#pragma once

#include <string>
#include "opencv\cv.hpp"

using namespace std;
using namespace cv;

class ImageOPtions
{
	string modification;
	string path;
	Mat image;
	const int pointsCount = 500;
	vector<KeyPoint> keyPoints;
	Mat descriptors;
	void calculateKeyPoints();
	void calculateDescriptors();
public:
	ImageOPtions();
	ImageOPtions(string pathInput, string modificationInput);
	string getPathToImage();
	string getModidfication();
	Mat getImage();
	vector<KeyPoint> getKeyPoints();
	Mat getDescriptors();
	~ImageOPtions();	
};

