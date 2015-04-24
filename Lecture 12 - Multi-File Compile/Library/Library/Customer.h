#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Book.h"

struct Customer {
	string firstName, lastName;
	string social;
	Book books[25];
	int numBooksCheckedOut;
};

bool loadCustomers(string filename, Customer custs[], int maxCusts, int &numCust);
bool writeCustomers(string filename, Customer custs[], int numCusts);
void printCustomers(Customer custs[], int numCusts);

#endif