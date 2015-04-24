#include<iostream>
#include<string>

using namespace std;
void printNames(string *x, int size);
int main()
{
	int i, numNames = 1;
	string *names = new string[numNames];
	string nxtName;

	names[0] = "Luke";

	while(true)
	{
		// Print Names
		cout << "Names: " << endl;
		printNames(names, numNames);

		// Enter Names
		cout << "Enter a Name to Add: ";
		cin >> nxtName;

		// Add nxtName to the array of names
		

	}



	return 0;
}



void printNames(string *x, int size)
{
	int i;
	for(i = 0; i < size; i++)
		cout << x[i] << endl;
	cout << endl;
	return;
}