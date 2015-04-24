// Need to include geomtery since the code below uses
// the Rectangle structures
#include "geometry.h"

double rectArea(Rectangle rect)
{
	double width = rect.LR.x - rect.UL.x;
	double height = rect.UL.y - rect.LR.y;
	return width * height;
}