#include<iostream>
using namespace std;

void circleProperties(double, double&, double&);



int main()
{
	double r = 4, area = 0, cir = 0;
	circleProperties(r, area, cir);
	cout << "Circle with radius of " << r << " has an area of ";
	cout << area << " and a circumference of " << cir << endl;

	r = 12.11;
	circleProperties(r, area, cir);
	cout << "Circle with radius of " << r << " has an area of ";
	cout << area << " and a circumference of " << cir << endl;

	return 0;
}


void circleProperties(double radius, double &area, double &circumference)
{
	area = radius * radius * 3.14;
	circumference = 2 * radius * 3.14;
	return;
}