#include<iostream>

using namespace std;

// Prototype
void printToConsole(int);

int main()
{

	int someVar = 8;
	// Function Calls
	printToConsole(5);			// With constant
	printToConsole(6);			// Different constant
	printToConsole(someVar);	// Passing a Variable
	printToConsole(someVar + 5); // With an Expression, expression is evaluated first

	return 0;
}

// User Defined Function
void printToConsole(int num)
{
	cout << "Number is " << num << endl;
	return;
}

