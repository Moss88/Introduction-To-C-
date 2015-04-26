#include<iostream>
using namespace std;

// Function Prototypes
double areaOfTriangle(double base, double height);
double areaOfRectangle(double width, double height);

int main()
{
	double width, height, area;
	char select;	

	// Menu Selection
	cout << "Select (R) to calculate the area of a rectangle, "<< endl;
	cout << "or (T) to calculate the area of a triangle." << endl;
	cout << "Select: ";
	cin >> select;

	if(select == 't')
	{
		// Code for the Triangle
		cout << "Enter in the base then the height: ";
		cin >> width >> height;
		area = areaOfTriangle(width, height);
	}
	else
	{
		if(select == 'r')
		{
			// Code for the Rectrangle
			cout << "Enter the width then the height: ";
			cin >> width >> height;
			area = areaOfRectangle(width, height);
		}
		else
		{
			// Otherwise Invalid Option
			cout << "Invalid option." << endl;
			return 0;
		}
	}

	// Final output
	cout << "The area is: " << area << endl;

	return 0;
}

double areaOfTriangle(double base, double height)
{
	return base * height * .5;
}

double areaOfRectangle(double width, double height)
{
	return width * height;
}
