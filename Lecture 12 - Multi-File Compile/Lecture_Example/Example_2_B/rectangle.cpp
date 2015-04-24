#include "rectangle.h"
// Function to Calculate Area
double rectArea(Rectangle rect)
{
	double width = rect.LR.x - rect.UL.x;
	double height = rect.UL.y - rect.LR.y;
	return width * height;
}