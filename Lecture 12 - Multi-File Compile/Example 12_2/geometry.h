// Header Guard, Protects against redeclartion
#ifndef GEOMETRY_H
#define GEOMETRY_H
// Need to include the file below since the code uses Point
#include "cartesian.h"

// Our New Structure
struct Rectangle {
	Point UL;
	Point LR;
};

double rectArea(Rectangle rect);

#endif