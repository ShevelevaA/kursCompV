#include <iostream>
#include "opencv\cv.hpp"
#include "opencv2\features2d.hpp"
#include "ImageOPtions.h"
#include "DescriptorOperations.h"

using namespace std;
using namespace cv;

void printInfo(DescriptorCompare descrComp) {
	cout << descrComp.modif << endl;
	cout << "���������� ������������: " << descrComp.origDescrCount << endl;
	cout << "���������� ������������ ���������������� � ����� ������������: " << descrComp.countNotFindAll << endl;
	cout << "���������� ������������ ���������� ��� ������� ������� � ����� ������������: " << descrComp.countFindAllMatch << endl;
	cout << "���������� ���������������� ������������ ��� '" << descrComp.modif1 << "' :" << descrComp.countNotFindInt + descrComp.countNotFindAll << endl;
	cout << "���������� �������������� ������������ ��� '" << descrComp.modif1 << "' :" << descrComp.countFindAllInt + descrComp.countFindAllMatch << endl;
	cout << "���������� ���������������� ������������ ��� '" << descrComp.modif2 << "' :" << descrComp.countNotFindInt2 + descrComp.countNotFindAll << endl;
	cout << "���������� �������������� ������������ ��� '" << descrComp.modif2 << "' :" << descrComp.countFindAllInt2 + descrComp.countFindAllMatch << endl;
	cout << "��������" << endl;
	cout << "������� ������� ��������� ����� ��������������� ������������� ����� �����������: " << descrComp.distFindAll / (descrComp.countFindAllMatch + descrComp.countFindAllInt2 + descrComp.countFindAllInt) << endl;
	cout << endl;
}

int main()
{
	Mat img = imread("C://Users/ks/Desktop/Lenna78.png", 0);
	setlocale(LC_CTYPE, "rus");
	ImageOPtions imageOrig = ImageOPtions("C://Users/ks/Desktop/Lenna.png", "��������");
	ImageOPtions imageIntensity = ImageOPtions("C://Users/ks/Desktop/Lenna111.png", "���������� �� 26");
	ImageOPtions imageIntensity2 = ImageOPtions("C://Users/ks/Desktop/Lenna112.png", "���������� �� 100");
	ImageOPtions imageRotate = ImageOPtions("C://Users/ks/Desktop/Lenna5.png", "������� 15 ��������");
	ImageOPtions imageRotate2 = ImageOPtions("C://Users/ks/Desktop/Lenna52.png", "������� -15 ��������");
	ImageOPtions imageScale = ImageOPtions("C://Users/ks/Desktop/Lenna4.png", "���������� � 2 ����");
	ImageOPtions imageScale2 = ImageOPtions("C://Users/ks/Desktop/Lenna78.png", "���������� � 3 ����");

	DescriptorCompare compIntensity = DescriptorOperations::compareDescriptors(imageOrig, imageIntensity, imageIntensity2, "���������� �����������");
	printInfo(compIntensity);

	DescriptorCompare compRotate = DescriptorOperations::compareDescriptors(imageOrig, imageRotate, imageRotate2, "������� �����������");
	printInfo(compRotate);

	DescriptorCompare compScale = DescriptorOperations::compareDescriptors(imageOrig, imageScale, imageScale2, "���������� ������� �����������");
	printInfo(compScale);

	system("pause");
	return 0;
}