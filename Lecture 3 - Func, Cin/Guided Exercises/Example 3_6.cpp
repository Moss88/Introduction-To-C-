#include<iostream>

using namespace std;

// Prototype
float division(float, float);

int main()
{

	float num, den;
	float result;

	cout << "Enter numerator then denominator: ";
	cin >> num >> den;

	
	// Multiple Parameters
	result = division(num, den);
	cout << "Result: " << result << endl;

	// Order Matters!, not the matching of the names
	cout << "With parameter order reversed:" << endl;
	result = division(den, num);
	cout << "Result: " << result << endl;

	return 0;
}

// User Defined Function
float division(float num, float den)
{
	return num / den;
}

