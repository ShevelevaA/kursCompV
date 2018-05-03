#include <iostream>
#include "opencv\cv.hpp"
#include "opencv2\features2d.hpp"
#include "ImageOPtions.h"
#include "DescriptorOperations.h"

using namespace std;
using namespace cv;

void printInfo(DescriptorCompare descrComp) {
	cout << descrComp.modif << endl;
	cout << "Количество дескрипторов: " << descrComp.origDescrCount << endl;
	cout << "Количество дескрипторов несопоставленных в обоих модификациях: " << descrComp.countNotFindAll << endl;
	cout << "Количество дескрипторов расстояние для которых совпало в обоих модификациях: " << descrComp.countFindAllMatch << endl;
	cout << "Количество несопоставленных дескрипторов для '" << descrComp.modif1 << "' :" << descrComp.countNotFindInt + descrComp.countNotFindAll << endl;
	cout << "Количество сопоставленных дескрипторов для '" << descrComp.modif1 << "' :" << descrComp.countFindAllInt + descrComp.countFindAllMatch << endl;
	cout << "Количество несопоставленных дескрипторов для '" << descrComp.modif2 << "' :" << descrComp.countNotFindInt2 + descrComp.countNotFindAll << endl;
	cout << "Количество сопоставленных дескрипторов для '" << descrComp.modif2 << "' :" << descrComp.countFindAllInt2 + descrComp.countFindAllMatch << endl;
	cout << "Стистика" << endl;
	cout << "Средняя разница дистанций между сопоставленными дескрипторами обоих модификаций: " << descrComp.distFindAll / (descrComp.countFindAllMatch + descrComp.countFindAllInt2 + descrComp.countFindAllInt) << endl;
	cout << endl;
}

int main()
{
	Mat img = imread("C://Users/ks/Desktop/Lenna78.png", 0);
	setlocale(LC_CTYPE, "rus");
	ImageOPtions imageOrig = ImageOPtions("C://Users/ks/Desktop/Lenna.png", "Оригинал");
	ImageOPtions imageIntensity = ImageOPtions("C://Users/ks/Desktop/Lenna111.png", "Осветление на 26");
	ImageOPtions imageIntensity2 = ImageOPtions("C://Users/ks/Desktop/Lenna112.png", "Осветление на 100");
	ImageOPtions imageRotate = ImageOPtions("C://Users/ks/Desktop/Lenna5.png", "Поворот 15 градусов");
	ImageOPtions imageRotate2 = ImageOPtions("C://Users/ks/Desktop/Lenna52.png", "Поворот -15 градусов");
	ImageOPtions imageScale = ImageOPtions("C://Users/ks/Desktop/Lenna4.png", "Уменьшение в 2 раза");
	ImageOPtions imageScale2 = ImageOPtions("C://Users/ks/Desktop/Lenna78.png", "Уменьшение в 3 раза");

	DescriptorCompare compIntensity = DescriptorOperations::compareDescriptors(imageOrig, imageIntensity, imageIntensity2, "Осветление изображения");
	printInfo(compIntensity);

	DescriptorCompare compRotate = DescriptorOperations::compareDescriptors(imageOrig, imageRotate, imageRotate2, "Поворот изображения");
	printInfo(compRotate);

	DescriptorCompare compScale = DescriptorOperations::compareDescriptors(imageOrig, imageScale, imageScale2, "Уменьшение размера изображения");
	printInfo(compScale);

	system("pause");
	return 0;
}