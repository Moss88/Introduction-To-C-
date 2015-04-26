#include<iostream>
#include<string>

using namespace std;


int main()
{
	int idxOfColon, num1 = 0, num2 = 0;
	string numbers = "2434:342";
	string strNum1, strNum2;

	// Grab index of colon, length of string is already known
	idxOfColon = numbers.find(':');

	// Split into two arrays to make the code simplier 
	strNum1 = numbers.substr(0, idxOfColon);
	strNum2 = numbers.substr(idxOfColon + 1, numbers.size() - idxOfColon - 1);
	
	// If the number is in a string form then
	// we can use atoi which converts a c string to an int
	num1 = atoi(strNum1.c_str());
	num2 = atoi(strNum2.c_str());

	// Output to console
	cout << "Number 1: " << num1 << endl;
	cout << "Number 2: " << num2 << endl;

	return 0;
}