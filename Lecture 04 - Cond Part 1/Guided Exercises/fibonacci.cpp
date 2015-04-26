#include<iostream>

using namespace std;

int main()
{
	
	int x1 = 0, x2 = 1, i = 0, y;
	const int n = 6;		// Only calculate six numbers in the sequence (8 will be diplayed since we display 2 prior to the loop)

	cout << x1 << ", " << x2 << ", "; 
	while(i < n)
	{
		y = x1 + x2;	// Computes next number in sequence
		x1 = x2;		// X1 is no longer needed, shift x2 into x1
		x2 = y;			// x2 is now copied in x1, so shift y into x2 to prepare for next number of the sequence 

		cout << y << ", ";
		i++;
	}
	cout << endl;


	return 0;
}