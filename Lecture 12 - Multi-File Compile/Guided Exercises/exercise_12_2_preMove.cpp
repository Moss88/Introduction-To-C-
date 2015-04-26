#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

class Employee {
public:
	string name;
	float rate;
	int hours;
};

class Bank {
public:
	Bank();
	bool loadFromFile(string path);
	bool writeToFile(string path);
	void addEmployee(Employee e);
	void fireEmployee(int id);
	void print();
private:
	Employee emps[10];
	int numEmp;
};

// Constructor
Bank::Bank() {
	numEmp = 0;
}

bool Bank::writeToFile(string path) {
	ofstream outFile;
	outFile.open(path.c_str());
	if(!outFile.is_open())
		return false;

	for(int i = 0; i < numEmp; i++)
	{
		outFile << emps[i].name << "," << emps[i].rate << "," << emps[i].hours;
		// Ensures no newline on last employee		
		if(i != numEmp - 1)
			outFile << endl;
	}
	outFile.close();
	return true;
}


bool Bank::loadFromFile(string path) {
	ifstream inFile;
	inFile.open(path.c_str());
	if(!inFile.is_open())
		return false;

	while(inFile.good())
	{
		string buffer, tmp;
		getline(inFile, buffer);
		if(buffer == "")
			continue;
		int loc1 = buffer.find(",");
		emps[numEmp].name = buffer.substr(0, loc1);
		int loc2 = buffer.find(",", loc1 + 1);
		tmp = buffer.substr(loc1 + 1, loc2-loc1-1);
		emps[numEmp].rate = atof(tmp.c_str());
		tmp = buffer.substr(loc2+1);
		emps[numEmp].hours = atoi(tmp.c_str());
		numEmp++;
	}
	inFile.close();
	return true;
}

void Bank::addEmployee(Employee e)
{
	if(numEmp < 10)
	{
		emps[numEmp] = e;
		numEmp++;
	}
}

void Bank::fireEmployee(int id)
{
	// Shift the array
	for(int i = id; i < numEmp - 1; i++)
		emps[i] = emps[i+1];
	numEmp--;
}


void Bank::print() {
	// Print Employees to Console
	cout << left << setw(25) << "Name:" << setw(6) << "Rate"  << setw(6) << "Hours"  << endl; 
	for(int i = 0; i < numEmp; i++)
	{
		cout << left << setw(3) << i << setw(25) << emps[i].name << setw(6) << emps[i].rate;
		cout << setw(6) << emps[i].hours << endl; 
	}
}
int main()
{
	Bank myBank;

	// Load all Data from File
	if(!myBank.loadFromFile("employees.txt"))
	{
		cout << "Error opening file" << endl;
		return 0;
	}

	// Menu to Manipulate Employees
	string select;
	while(select != "Exit")
	{
		cout << "Make a selection: " << endl;
		cout << "Print: print Employees" << endl;
		cout << "Add: Add an employee" << endl;
		cout << "Fire: Remove a terrible employee" << endl;
		cout << "Exit: to exit the program" << endl;
		cout << "Selection: ";
		cin >> select;

		if(select == "Add")
		{
			Employee tmp;
			cout << "Name: ";
			cin >> tmp.name;
			cout << "Rate: ";
			cin >> tmp.rate;
			cout << "Hours: ";
			cin >> tmp.hours;
			myBank.addEmployee(tmp);
		}
		else if(select == "Print")
			myBank.print();
		else if(select == "Fire")
		{
			int id;
			myBank.print();
			cout << "Enter an ID to fire: ";
			cin >> id;
			myBank.fireEmployee(id);
		}
	}
	
	
	// Write file back to update changes
	if(!myBank.writeToFile("employees.txt"))
		cout << "Failed to write to the file" << endl;
	


	return 0;
}
