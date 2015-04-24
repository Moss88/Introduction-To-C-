#include<iostream>
using namespace std;

int main()
{
	int bin, dec, bit, value;

	// Step 1: User Input
	cout << "Enter the binary number to convert: ";
	cin >> bin;

	// Step 2: Calculation
	dec = 0;
	value = 1;
	while(bin > 0)
	{
		// Calculate Value of bit
		bit = bin % 2;		// Determines if LSB bit is 1 or 0
		dec =  dec + bit * value;	// Multiple bit by power of two	
		
		// Update Binary number and Multiplier for next iteration
		bin = bin / 10; // Remove Digit		
		value = value * 2; // Next Power of Two  so if 2^2 now it will be 2^3
	}
	
	// Step 3: Feedback
	cout << "Decimal number is: " << dec << endl;
	return 0;
}
