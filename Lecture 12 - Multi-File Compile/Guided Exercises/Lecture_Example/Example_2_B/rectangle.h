#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "point.h"
struct Rectangle {
	Point UL;		// Upper Left Point
	Point LR;		// Lower Right Point
};

double rectArea(Rectangle rect);

#endif