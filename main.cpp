#define cimg_use_jpeg

#include <iostream>
#include <Windows.h>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

int main()
{	
	const int sLength = 67;
	const int maxPixelAmount = 255;
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	

	CImg<unsigned char>image("coffee.jpg");
	char bChar_Array[sLength];
	string bChars = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

	strcpy_s(bChar_Array, bChars.c_str());

	image.resize(80, 60);

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	int w = csbi.srWindow.Right - csbi.srWindow.Left + 1;;
	int h = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	cimg_forXY(image, x, y) {

		int R = (int)image(x, y, 0, 0);
		int G = (int)image(x, y, 0, 1);
		int B = (int)image(x, y, 0, 2);

		float grayValue = 0.33*R + 0.33*G + 0.33*B;
		int pixelToAscii = grayValue / maxPixelAmount * sLength - 1;
		
		w = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		h = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		std::cout << bChar_Array[pixelToAscii];
	}


	return 0;

}