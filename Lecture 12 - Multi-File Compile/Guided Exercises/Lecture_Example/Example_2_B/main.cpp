#include <iostream>
#include "rectangle.h"
#include <Windows.h>
using namespace std;
int main()
{
	#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i;

	cout << "Multiplication Table:" << endl;
	// Repeat of Top Line
	cout << setw(3) << " ";
	for(i = 1; i <=10; i++)
		cout << i;
	cout << endl;
	
	// Print Table
	for(i = 1; i <= 9; i++)
	{
		cout << setw(3) << i;   // Repeat of first column
		for(j = 1; j <= 9; j++)
			cout << setw(3) << row*j;
		cout << endl;
	}

	return 0;
}


	return 0;
}

