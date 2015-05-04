#include <iostream>

using namespace std;

void printDescending(int n)
{
	// Base Case
	if(n == 0)
		return;
	// Print and then descending into next function
	cout << n << " ";
	printDescending(n - 1);	// Here we call the function from within itself so therefore it is recurisve
}


int main() {
	printDescending(5);
	cout << endl;
	return 0;
}
