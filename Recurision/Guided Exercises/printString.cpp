#include <iostream>
#include <string>
using namespace std;

void printString(string str, int pos)
{
	// Base Case
	if(pos == str.size())
		return;
	// Print Character and Recurse
	cout << str[pos];
	printString(str, pos + 1);
}

void printStringReverse(string str, int pos)
{
	// Base Case
	if(pos == str.size())
		return;
	// Recurse then print character
	// Here we descend all the way to the base case
	// before we start printing characters. Thus it
	// works like a stack where the last character
	// visited is the first to be printed.
	printString(str, pos + 1);
	cout << str[pos];
}


int main() {
	string myStr;
	cout << "Enter a word: ";
	cin >> myStr;

	cout << "String Forwards:" << endl;
	printString(myStr, 0);
	cout << endl;

	cout << "String Backwards:" << endl;
	printStringReverse(myStr, 0);
	cout << endl;
	return 0;
}
