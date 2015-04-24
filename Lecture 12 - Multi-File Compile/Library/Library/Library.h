#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Customer.h"

struct Library
{
	static const int maxBooks = 100;
	static const int maxCust = 20;
	Customer customers[maxCust];
	Book books[maxBooks];
	int numBooks;
	int numCusts;

	string fCustomers;
	string fBooks;
};





#endif