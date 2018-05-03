#pragma once
#include "ImageOPtions.h"

struct DescriptorCompare
{
	string modif;
	string modif1;
	string modif2;
	int origDescrCount;
	vector<double> difDistance;
	double distFindAll = 0;
	int countFindAllInt = 0;
	int countFindAllInt2 = 0;
	int countNotFindAll = 0;
	int countNotFindInt = 0;
	int countNotFindInt2 = 0;
	int countFindAllMatch = 0;
};