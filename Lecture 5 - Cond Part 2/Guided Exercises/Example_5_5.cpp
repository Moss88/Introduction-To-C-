#include <iostream>
using namespace std;


int main ()
{
	int base, exp, i, result;

	// Fetch User Information
	cout << "Enter the base: ";
	cin >> base;
	cout << "Enter the exponent: ";
	cin >> exp;

	for(result = 1, i = 0; i < exp; i++)
		result = base * result;
	
	cout << "Result is: " << result << endl;



	return 0;
	
}
	
