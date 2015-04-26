#include <iostream>
using namespace std;


int main ()
{
	float num1, num2, result;
	char op;

	cout << "Enter in two numbers: " << endl;
	cin >> num1 >> num2;

	cout << "Select your operator (+, -, *): ";
	cin >> op;

	switch(op)
	{
		case '-':
			result = num1 - num2;
			break;
		case '+':
			result = num1 + num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		default:
			cout << "Invalid operator" << endl;
	}
	cout << "Result is: " << result << endl;
	return 0;
	
}
	
