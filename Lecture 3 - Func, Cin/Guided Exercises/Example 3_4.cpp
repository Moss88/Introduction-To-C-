#include<iostream>

using namespace std;

// Prototype
int increment(int);

int main()
{

	int someVar = 8;
	int output;

	// Function Calls
	output = increment(3);			// With constant
	cout << "Output is: " << output << endl;

	output = increment(someVar);	// With Variable
	cout << "Output is: " << output << ", someVar is: " << someVar << endl;

	output = increment(output);		// Assign Back
	cout << "Output is: " << output << ", someVar is: " << someVar << endl;


	return 0;
}

// User Defined Function
int increment(int num)
{
	int x = num + 1;
	return x;
}

