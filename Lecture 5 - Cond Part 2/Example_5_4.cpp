#include <iostream>
using namespace std;


int main ()
{
	int base, height;
	float area;
	char select = 'y';
	while(select == 'y' || select == 'Y')
	{
		cout << "Enter (r) to calculate the area of a rectangle" << endl;
		cout << "or (t) to calculate the area of a triangle" << endl;
		cout << "Select: ";
		cin >> select;

	
		if(select == 'r' || select == 'R')
		{
			cout << "Enter the width then the height of the rectangle" << endl;
			cin >> base >> height;
			area = base * height;
			cout << "The area of the rectangle is: " << area << endl;
		}
		else if(select == 't' || select == 'T')
		{
			cout << "Enter the base then the height of the triangle" << endl;
			cin >> base >> height;
			area = base * height * .5;
			cout << "The area of the triangle is: " << area << endl;
		}
		else
			cout << "Invalid selection" << endl;
		

		
	
		cout << "Repeat? (y\\n): ";
		cin >> select;

	}

	return 0;
	
}
	
