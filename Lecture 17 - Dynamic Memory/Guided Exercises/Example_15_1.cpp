#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	double *number, mean, var;
	int size, i;

	cout << "Enter the size of your set of numbers: ";
	cin >> size;

	number = new double[size];

	// Initialize and sum the numbers
	for(i = 0, mean = 0; i < size; i++)
	{
		cout << "Enter a number: ";
		cin >> number[i];
		mean += number[i];
	}
	// Finish calculation of mean
	mean /= size;
	
	// Calculate Variance
	// Sum the square of the diff
	for(i = 0, var = 0; i < size; i++)
		var += pow(number[i] - mean, 2);
	// Divide by n
	var /= size;

	cout << "Mean is: " << mean << endl;
	cout << "Variance is: " << var << endl;
	
	// Deallocate To Prevent Memory Leak
	delete [] number;
	
	return 0;
}