#include <iostream>

using namespace std;

int factorial(int n)
{
	// Base Case
	if(n == 1)
		return n;
	return factorial(n - 1) * n;
}

// Warning: the factorial result gets very large very quickly
// use a small number for n, otherwise the result will overflow
int main() {
	int num;
	cout << "Enter n for n!: ";
	cin >> num;
	cout << "Result is " << factorial(num) << endl;
	return 0;
}
