#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;


struct Point {
	double x, y;
};

struct Rectangle {
	Point UL, LR;
};


int main()
{
	Rectangle rect;
	rect.UL.x = 1;
	rect.UL.y = 4;

	rect.LR.x = 5;
	rect.LR.y = 1;


	return 0;	
}
	
	/*
	string itemName;
	double unitPrice, pricePerItem, sum = 0;
	int quantity;
	char b[3][3];

	
	// Step 1: Declare Stream
	ifstream inFile;
	ofstream outFile;

	// Step 2: Open File
	inFile.open(".\\items.txt");
	outFile.open(".\\prices.txt");
	// Step 3: Check if File is Open
	if(!inFile.is_open() || !outFile.is_open())
	{
		cout << "Error opening file." << endl;
		return 0;
	}

	// Step 4: Read File Contents
	while(inFile.good())
	{
		inFile >> itemName >> unitPrice >> quantity;
		pricePerItem = quantity * unitPrice;
		sum += pricePerItem;
		outFile << itemName <<  fixed << setprecision(2) << " $" << pricePerItem << endl;
		cout << itemName <<  fixed << setprecision(2) << " $" << pricePerItem << endl;
	}
	cout << endl << "Total: $" <<fixed << setprecision(2) << sum << endl;
	outFile << endl << "Total: $" <<fixed << setprecision(2) << sum << endl;
	
	// Step 5: Close File
	inFile.close();
	outFile.close();
	return 0;
}
*/
