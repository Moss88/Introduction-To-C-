#include<iostream>
#include<cmath>

using namespace std;

// Order of class definition matters here
// the compiler starts from the top down and must know
// what a Point is before Rectangle since Rectangle 
// uses the point class
class Point {
public:
	double x, y;
};

class Rectangle {
public:
	Point UL;	// Upper Left
	Point LR;	// Lower Right
};

// Function Prototypes
// For the same reason as above, function prototypes should occur after
// class definition
Rectangle initRect(double, double, double, double);
void printRect(Rectangle);
double calcAreaOfRect(Rectangle);
Rectangle offsetRectangle(Rectangle, double, double);


int main()
{
	Rectangle rect;
	// Upper Left Point (0, 4), Lower Right Point (6, 0)
	rect = initRect(0, 4, 6, 0);
	// Print the rectangle to console
	printRect(rect);
	// Calculate Area
	cout << "Area of rectangle is " << calcAreaOfRect(rect) << endl;
	// Shift Rectangle over up one, and right one
	rect = offsetRectangle(rect, 1, 1);
	// Verify the shift worked
	printRect(rect);

	return 0;
}

// Initializes the data in the rectangle class
// to the two points specified in the arguements
Rectangle initRect(double x1, double y1, double x2, double y2)
{
	Rectangle r;
	r.UL.x = x1;
	r.UL.y = y1;
	r.LR.x = x2;
	r.LR.y = y2;
	return r;
}

// Prints the data in the rectangle class
void printRect(Rectangle r)
{
	cout << "(" << r.UL.x << ", " << r.UL.y << ")";
	cout << "(" << r.LR.x << ", " << r.LR.y << ")" << endl;
}

// Calculates the area of a rectangle
double calcAreaOfRect(Rectangle r)
{
	double area;
	area = abs(r.UL.x - r.LR.x) * abs(r.UL.y - r.LR.y);
	return area;
}

// Shifts the rectangle on the grid
Rectangle offsetRectangle(Rectangle r, double x, double y)
{
	r.UL.x += x;
	r.LR.x += x;
	r.UL.y += y;
	r.LR.y += y;
	return r;
}

