#include<iostream>
#include<string>

using namespace std;
void printNames(string *x, int size);
int main()
{
	int i, numNames = 1;
	string *names = new string[numNames];
	string *tmp, nxtName;

	names[0] = "Luke";

	while (true)
	{
		// Print Names
		cout << "Names: " << endl;
		printNames(names, numNames);

		// Enter Names
		cout << "Enter a Name to Add: ";
		cin >> nxtName;


		// Add nxtName to the array of names
		// Step 1: Allocate New Array to Temp Pointer
		tmp = new string[numNames + 1];

		// Step 2: Copy Contents from Original Array to New Array
		for (i = 0; i < numNames; i++)
			tmp[i] = names[i];

		// Step 3: Add Item to end of array and update item count
		tmp[numNames] = nxtName;
		numNames++;

		// Step 4: Deallocate old Array
		delete[] names;

		// Step 5: Update Original Pointer to Point to new Array
		names = tmp;
	}



	return 0;
}



void printNames(string *x, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << x[i] << endl;
	cout << endl;
	return;
}