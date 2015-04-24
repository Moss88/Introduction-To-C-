#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;

class Employee {
	public:
	string name;
	float rate;
	int hours;
};


int main()
{
	// Arrays to Hold Information
	Employee employees[10];
	int numEmployees = 0;

	// Step 1: Open File Stream
	ifstream inFile;

	// Step 2: Open File
	inFile.open("employees.txt");

	// Step 3: Check for Success
	if(!inFile.is_open())
	{
		cout << "Failed to properly open file" << endl;
		return 0;
	}


	// Step 4: Read In File
		
	while(inFile.good())
	{
		string buffer;
		stringstream ss;
		
		// Fetch Line from File
		getline(inFile, buffer);

		// Check for blank line, if blank read another line
		if(buffer == "")
			continue;

		// Fetch before semi, this is the name		
		int semiPos = buffer.find(";");
		employees[numEmployees].name = buffer.substr(0, semiPos);
		
		// Place everything after semi into the stream
		ss << buffer.substr(semiPos + 1);

		// Convert and place into arrays
		ss >> employees[numEmployees].rate >> employees[numEmployees].hours;
		numEmployees++;
	}

	// Step 5: Close File
	inFile.close();


	// Perform Computations and print to the console in table form
	// setw: sets the minimal width of the output, field is padded with spaces if not fully used
	// fixed: ensures a decimal point is displayed
	// setprecision: with fixed, sets number of decimal places to display
	int i;
	cout << left << setw(23) << "Name" << setw(7) << "Rate" << setw(7) << "Hours" << "Wage" << endl;
	for(i = 0; i < numEmployees; i++)
	{
		cout << left << setw(23) << employees[i].name <<fixed << setprecision(2) << setw(7) << employees[i].rate;
		cout << setw(7) << employees[i].hours << "$" << employees[i].rate * employees[i].hours << endl;
	}

	


	return 0;
}
