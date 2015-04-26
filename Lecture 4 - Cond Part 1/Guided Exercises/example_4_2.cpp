#include<iostream>
using namespace std;

int main()
{
	float inTemp, calcTemp;
	int select;	

	// Step 1: User Input
	cout << "Select from the following options:" << endl;
	cout << "1: To convert from Celsius to Fahrenheit."<< endl;
	cout << "2: To convert from Celsius to Kelvin." << endl;
	cout << "3: To convert from Fahrenheit to Celsius." << endl;
	cout << "Select: ";
	cin >> select;


	// Step 2: Calculation
	if(select == 1)
	{
		cout << "Enter the temperature to be converted: ";
		cin >> inTemp;
		
		if(inTemp < -273.15)
		{
			cout << "Invalid Temperature. " << endl;
			return 0;
		}
		else
		{
			// C to K
			calcTemp = inTemp + 273;
		}	
	}
	else 
	{
		if(select == 2)
		{
			cout << "Enter the temperature to be converted: ";
			cin >> inTemp;		

			if(inTemp < -273.15)
			{
				cout << "Invalid Temperature. " << endl;
				return 0;
			}
			else
			{
				// C to F
				calcTemp = inTemp * 1.8 + 32;
			}	
		}
		else 
		{
			if(select == 3)
			{
				cout << "Enter the temperature to be converted: ";
				cin >> inTemp;

				if(inTemp < -459.67)
				{
					cout << "Invalid Temperature. " << endl;
					return 0;
				}
				else
				{
					// F to C
					calcTemp = (inTemp - 32) / 1.8;
				}				
			}
			else
			{
				// Catches selections that are not 1-3
				cout << "Invalid selection." << endl;
				return 0;
			}
		}
	}
	// Step 3: Feedback
	cout << "The converted temperature is " << calcTemp << endl;

	return 0;
}
