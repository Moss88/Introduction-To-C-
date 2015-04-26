#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	const int n = 10;
	int x[n], tmp, i;

	// Seed the random number generator
	srand(time(NULL));

	// Randomly Initialize and print the Array
	for(i = 0; i < n; i++)
	{
		x[i] = rand() % 100;
		cout << x[i] << " ";	
	}
	cout << endl;

	// Reverse the order of the array
	// Since we are swaping in place we only need to iterate
	// through half the array
	for(i = 0; i < n/2; i++)
	{
		// Perform Swap between positions in the array
		tmp = x[i];
		x[i] = x[n - 1 - i];
		x[n - 1 - i] = tmp; 
	}

	// Print the array to verify the results
	for(i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;


	return 0;
}
