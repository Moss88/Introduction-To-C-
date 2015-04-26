#include<iostream>

using namespace std;


int main()
{
	// Initialize the Contents of the Array
	int v1[5] = {2, 4, 5, 7, 3};
	int v2[5] = {3, 6, 4, 9, 2};
	int v3[5], i;

	// Add the arrays together
	for(i = 0; i < 5; i++)
		v3[i] = v1[i] + v2[i];

	// Print the Array to the Console
	for(i = 0; i < 5; i++)
		cout << v3[i] << " ";
	cout << endl;

	return 0;
}
