#include <iostream>
#include "shapes.h"

using namespace std;
int main()
{
	double width = 8, height = 3;
	double tArea, rArea;

	// Function Calls
	tArea = triArea(width, height);
	rArea = rectArea(width, height);

	cout << "Area of Triangle: " << tArea << endl;
	cout << "Area of Rectangle: " << rArea << endl;

	return 0;
}


