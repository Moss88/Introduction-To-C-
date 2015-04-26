#include<iostream>
using namespace std;

int main()
{
	int bin, dec, bit, multiplier;

	// Step 1: User Input
	cout << "Enter the decimal number to convert: ";
	cin >> dec;

	// Step 2: Calculation
	bin = 0;
	multiplier = 1;
	while(dec > 0)
	{
		// Calculate Bit and add it to the binary number
		// multiplier determines which digit is added
		bit = dec % 2;
		bin =  bin + bit * multiplier;		
		
		// Update Decimal number and Multiplier for next iteration
		dec = dec / 2;		
		multiplier = multiplier * 10;
	}
	
	// Step 3: Feedback
	cout << "Binary number is: " << bin << endl;
	return 0;
}
