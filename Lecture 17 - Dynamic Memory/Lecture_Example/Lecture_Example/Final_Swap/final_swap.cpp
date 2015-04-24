#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

void printArray(int *x, int size);

int main()
{
	int i;
	int *arr1 = new int[10];
	int *arr2 = new int[10];
	int *tmp;

	srand((unsigned int)time(NULL));

	for (i = 0; i < 10; i++)
	{
		arr1[i] = rand() % 20;
		arr2[i] = rand() % 20;
	}

	cout << "Array 1: ";
	printArray(arr1, 10);
	cout << "Array 2: ";
	printArray(arr2, 10);


	// Perform Swap
	tmp = arr1;
	arr1 = arr2;
	arr2 = tmp;


	cout << endl << "After Swap: " << endl;
	cout << "Array 1: ";
	printArray(arr1, 10);
	cout << "Array 2: ";
	printArray(arr2, 10);

	delete[] arr1;
	delete[] arr2;

	return 0;
}

void printArray(int *x, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << setw(4) << x[i];
	cout << endl;
	return;
}