#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	double price, total = 0;
	int quantity;
	string item;

	// Step 1: Declare a input file stream named inFile
	ifstream inFile;

	// Step 2: Open file (relative path in this case)
	// Assumption is items.txt is in the same directory as the current path
	inFile.open("items.txt");

	// Step 3: Check if File is open
	if(!inFile.is_open())
	{
		cerr << "Error opening file" << endl;
		return 0;
	}
	

	while(inFile.good())
	{
		// Step 4: Read in items from file
		// Order of read is very important
		inFile >> item >> price >> quantity;
		total += quantity * price;
		cout << item << " " << price * quantity << endl;
	}
	cout << "Total: " << total << endl;

	// Step 5 - Close File
	inFile.close();

	return 0;
}