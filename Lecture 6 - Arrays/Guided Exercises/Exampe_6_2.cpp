#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

int main()
{
	const int size = 10;
	int numbers[size];
	int i;

	srand(time(NULL));  // Seeds random number generator

	// Fill in Random Numbers
	for(i = 0; i < size; i++)
	{
		numbers[i] = (rand() % 100) + 1; // modulus reduces the range of the random number
	}

	// Cout Random Numbers in Array
	for(i = 0; i < size; i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;
	return 0;
}