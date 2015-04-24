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
	void print();
	bool loadFile(string path);
private:
	Employee emps[10];
	int numEmp;
};

Bank::Bank() {
	numEmp = 0;
}

bool Bank::loadFile(string path) {
	ifstream inFile;
	inFile.open(path.c_str());
	if(!inFile.is_open())
		return false;

	while(inFile.good())
	{
		string buffer, tmp;
		getline(inFile, buffer);
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

void Bank::print() {
	cout << left << setw(25) << "Name:" << setw(6) << "Rate"  << setw(6) << "Hours"  << endl; 
	for(int i = 0; i < numEmp; i++)
	{
		cout << left << setw(25) << emps[i].name << setw(6) << emps[i].rate << setw(6) << emps[i].hours << endl; 
	}
}



int main()
{
	Bank myBank;
	
	if(!myBank.loadFile("employees.txt"))
		cout << "Failed to load employees file. Continuing on." << endl;

	string select;
	while (select != "exit")
	{
		cout << "Select an option:" << endl;
		cout << "print: print Employees" << endl;
		cout << "exit: to exit program" << endl;
		cout << "selection: ";
		cin >> select;
		
		if(select == "print")
			myBank.print();
	}
	
	


	return 0;
}
