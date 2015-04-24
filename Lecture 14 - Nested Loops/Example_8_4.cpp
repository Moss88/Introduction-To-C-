#include <iostream>
#include <string>
#include <ctime>

using namespace std;
int main()
{
	int x[20], i, j, lowIdx, tmp;
	
	// Fill With Random Numbers
	srand((unsigned int)time(NULL));
	for(i = 0; i < 20; i++)
		x[i] = rand() % 100;

	// Print Random Numbers
	for(i = 0; i < 20; i++)
		cout << x[i] << " ";
	cout << endl;

	// Sorting Algorithm
	for(i = 0; i < 20; i++)
	{
		// Search for Lowest Number
		for(j = i, lowIdx = i; j < 20; j++)
		{
			if(x[j] < x[lowIdx])
				lowIdx = j;
		}
		// Swap
		tmp = x[i];
		x[i] = x[lowIdx];
		x[lowIdx] = tmp;
	}

	// Print Array
	for(i = 0; i < 20; i++)
		cout << x[i] << " ";
	cout << endl;

	return 0;
}
