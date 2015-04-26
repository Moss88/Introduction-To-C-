#include "Customer.h"

bool loadCustomers(string filename, Customer custs[], int maxCusts, int &numCust)
{
	ifstream file(filename);
	if(!file.is_open())
		return false;

	numCust = 0;
	while(file.good() && (numCust < maxCusts))
	{
		file >> custs[numCust].firstName >> custs[numCust].lastName >> custs[numCust].social;
		custs[numCust].numBooksCheckedOut = 0;
		numCust++;
	}

	file.close();

	return true;
}

bool writeCustomers(string filename, Customer custs[], int numCusts)
{
	ofstream file(filename);
	int i;

	if(!file.is_open())
		return false;

	for(i = 0; i < numCusts; i++)
	{
		if(i == 0)
			file << custs[i].firstName << " " << custs[i].lastName << " " << custs[i].social;
		else
			file << endl << custs[i].firstName << " " << custs[i].lastName << " " << custs[i].social;
	}

	file.close();
	return true;
}

void printCustomers(Customer custs[], int numCusts)
{
	int i;
	for(i = 0; i < numCusts; i++)
		cout << custs[i].lastName << ", " << custs[i].firstName << "\t" << custs[i].social << endl;

}