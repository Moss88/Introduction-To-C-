#include<iostream>

using namespace std;

// Prototype
float currencyConversion(float, float);

int main()
{

	float dollars = 8.15;
	float convRate;  // Usually Around 0.73
	float euros;

	cout << "Enter the number of dollars: ";
	cin >> dollars;

	cout << "Enter the conversion rate: ";
	cin >> convRate;

	// Multiple Parameters
	euros = currencyConversion(dollars, convRate);
	cout << dollars << " dollars is equivalent to " << euros << " euros" << endl;


	

	return 0;
}

// User Defined Function
float currencyConversion(float dollars, float convRate)
{
	return dollars * convRate;
}

