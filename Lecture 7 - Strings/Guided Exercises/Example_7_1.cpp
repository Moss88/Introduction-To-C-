#include<iostream>

using namespace std;


int main()
{
	const int n = 20;
	int i, j, x, y;
	char numbers[n] = "2434:342";
	char num[n];

	// Find Colon Position
	for(i = 0, j = 0; i < n && numbers[i] != '\0'; i++, j++)
	{
		// Copy Contents from one string to another
		num[j] = numbers[i];

		if(numbers[i] == ':')
		{
			// Make valide string, convert first number to integer
			num[j] = '\0';	
			x = atoi(num);
			j = -1;		// Reset index
		}
	}
	// Add String Terminator to make it a valid string
	num[j] = '\0';

	y = atoi(num);

	// Display Results
	cout << "x = " << x << ", " << "y = " << y << endl;

	return 0;
}
