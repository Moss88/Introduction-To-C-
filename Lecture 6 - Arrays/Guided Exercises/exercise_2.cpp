#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	const int n = 10;
	int x[n], lowest, i;

	// Seed the random number generator
	srand(time(NULL));

	// Randomly Initialize and print the Array
	for(i = 0; i < n; i++)
	{
		x[i] = rand() % 100;
		cout << x[i] << " ";	
	}
	cout << endl;

	// Find the Lowest Number in the Array
	// Start by assuming the lowest number is in the first position
	// then update assumption if a lower number is found
	for(lowest = x[0], i = 1; i < n; i++)
	{
		if(x[i] < lowest)
			lowest = x[i];
	}

	cout << "Lowest Number is: " << lowest << endl;


	return 0;
}
