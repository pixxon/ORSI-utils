#include "include/bmp_image.h"
#include "include/math_evaluator.h"

#include <fstream>
#include <iostream>

void testBMPImage()
{
	BMPImage image(640, 480);
	
	for(uint32_t ColIndex = 100; ColIndex < 300; ColIndex++)
	{
		for(uint32_t RowIndex = 250; RowIndex < 300; RowIndex++)
		{
			image.setColor(ColIndex, RowIndex, Color(255, 0, 0));
		}
		for(uint32_t RowIndex = 30; RowIndex < 80; RowIndex++)
		{
			image.setColor(ColIndex, RowIndex, Color(0, 255, 0));
		}
	}
	
	std::ofstream out("output.bmp");
	out << image;
	out.close();
}

void testMathEvaluator()
{
	MathEvaluator evaluator("x+2");
	std::cout << evaluator.calculate(3) << std::endl;
}

int main()
{
	testBMPImage();
	testMathEvaluator();
	
	return 0;
}