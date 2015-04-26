#include<iostream>
#include<iomanip>

using namespace std;

void exercise1();
void exercise2();
void exercise3();

int main()
{
	exercise1();
	exercise2();
	exercise3();
	
	return 0;
}

void exercise1()
{
	int i;
	// Start i at 10 and then decrement by 1 until zero is reached
	for(i = 10; i > 0; i--)
		cout << i << "..." << endl;
	cout << "Go!!!" << endl;
}

void exercise2()
{
	const int n = 100000;
	int i, den = 1, neg = 1;
	double result = 0;

	// Loop for n number of times, bigger the n, the closer to PI
	for(i = 0; i < n; i++)
	{
		// Result is the running sum of fractions
		result += 1.0/den * neg; 
		den += 2;				// Increase the denominator by 2
		neg *= - 1;				// Alternate the Sign
	}
	
	// Multiple the sum of fractions by 4
	result *= 4;
	cout << "Result is: " << std::setprecision(10) << result << endl;
}



void exercise3()
{
	int number;
	double prevAprox, nextAprox, diff = 0;
	
	// Get Number from User
	cout << "Enter a number to be square rooted: ";
	cin >> number;

	// Start with a reasonable guess
	prevAprox = number / 2;

	do
	{
		// Get the next Approximation
		nextAprox = ((number / prevAprox) + prevAprox)/2;

		// Compute the difference between approximations
		diff = prevAprox - nextAprox;
		
		// Store new approximation as previous for next loop		
		prevAprox = nextAprox;
		
	}while(diff > .00001 || diff < -.00001);  // Diff could be negative

	cout << "Square root is: " << prevAprox << endl;

}




/*
void exercise3()
{
	int number, n, i;
	
	cout << "Enter a number: ";
	cin >> number;

	n = number / 2; // Anything past half the number will not divide evenly
	for(i = 2; i < n; i++)
	{
		if(number % i == 0)
		{
			cout << "Number is not prime" << endl;
			break;
		}
	}

	if(i == n)
		cout << "Number is prime" << endl;

}

// Here is a more optimal solution which takes half the time
void optExercise3()
{
	int number, n, i;
	
	cout << "Enter a number: ";
	cin >> number;

	
	if(number % 2 == 0 && number != 2)
	{
		cout << "Number is not prime." << endl;
		return;
	}

	n = number / 2; // Anything past half the number will not divide evenly
	// Notice only the odd numbers are used for division
	// Since the number can't be divided by two, all even divisors can be ruled out
	for(i = 3; i < n; i += 2)
	{
		if(number % i == 0)
		{
			cout << "Number is not prime" << endl;
			break;
		}
	}

	if(i >= n)
		cout << "Number is prime" << endl;

}

*/
