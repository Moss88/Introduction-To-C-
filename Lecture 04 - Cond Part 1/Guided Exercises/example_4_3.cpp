#include<iostream>
using namespace std;

int main()
{
	float interestRate, principle;
	int maxYear, curYear;

	// Step 1: User Input
	cout << "Enter in the principle: ";
	cin >> principle;

	cout << "Enter in the interest rate: ";
	cin >> interestRate;


	cout << "Enter in the the number of years: ";
	cin >> maxYear;

	// Step 2: Calculation
	curYear = 0;
	while(curYear < maxYear)
	{
		principle = principle + principle * interestRate;
		curYear++;
	}
	
	// Step 3: Feedback
	cout << "Your balance after " << maxYear << " years will be $" << principle << endl;
	return 0;
}
