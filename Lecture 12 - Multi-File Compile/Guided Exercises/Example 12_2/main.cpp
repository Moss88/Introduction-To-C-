#include <iostream>

// Include geomtery to include the prototypes for the
// functions we will be using
#include "geometry.h"

using namespace std;
int main()
{
	Rectangle rect;
	rect.UL.x =1;
	rect.UL.y =4;
	rect.LR.x =4;
	rect.LR.y =0;

	double area = rectArea(rect);
	cout << "Area is: " << area << endl;


	return 0;
}