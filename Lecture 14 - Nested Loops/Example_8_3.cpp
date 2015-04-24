#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i, j;

	cout << "Multiplication Table:" << endl;
	// Repeat of Top Line
	cout << setw(3) << " ";
	for(i = 1; i <=9; i++)
		cout << setw(3) << i;
	cout << endl;
	
	// Print Table
	for(i = 1; i <= 9; i++)
	{
		cout << setw(3) << i;   // Get the repeat of first column
		for(j = 1; j <= 9; j++)
			cout << setw(3) << i*j;
		cout << endl;
	}

	return 0;
}