#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int *arr, size;
	
	cout << "Enter Size of the Array: ";
	cin >>size;

	// Call Function to Generate Function
	

	// Print Array
	printArray(arr, size);

	// Deallocate Array
	delete [] arr;

	return 0;
}


void printArray(int x[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		cout << setw(4) << x[i];
	cout << endl;

}
