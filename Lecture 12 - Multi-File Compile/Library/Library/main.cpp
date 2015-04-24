#include "Book.h"
#include "Library.h"
#include "Customer.h"

void printMenu();

int main()
{
	Library lib;
	int select = 0;
	
	lib.fBooks = "books.txt";
	lib.fCustomers = "customers.txt";

	// Load Books
	if(!loadBooks(lib.fBooks, lib.books, lib.maxBooks, lib.numBooks))
	{
		cout << "Failed to Load Books" << endl;
		return 0;
	}

	// Load Customers
	if(!loadCustomers(lib.fCustomers, lib.customers, lib.maxCust, lib.numCusts))
	{
		cout << "Failed to Load Customers" << endl;
		return 0;
	}

	// Menu
	while(select != 6)
	{
		printMenu();
		cin >> select;
		cout << endl;

		if(select == 1)
		{
			// List Books
			printBooks(lib.books, lib.numBooks);
		}
		else if(select == 2)
		{
			// Add Book To Deposit
			cout << "Book Title: ";
			cin.ignore();
			getline(cin, lib.books[lib.numBooks].title);

			cout << "Year Published: ";
			cin >> lib.books[lib.numBooks].yearPublished;
			
			cout << "Number of Pages: ";
			cin >> lib.books[lib.numBooks].pages;
			
			lib.books[lib.numBooks].checkedOut = false;
			lib.numBooks++;
			
			cout << "Book added." << endl << endl;
		}
		else if(select == 4)
		{
			// List Customers
			printCustomers(lib.customers, lib.numCusts);
		}
		else if(select == 5)
		{
			// Add Customer to Library
			cout << "First and Last Name: ";
			cin >> lib.customers[lib.numCusts].firstName >> lib.customers[lib.numCusts].lastName;

			cout << "Social Security: ";
			cin >> lib.customers[lib.numCusts].social;
			lib.customers[lib.numCusts].numBooksCheckedOut = 0;
			lib.numCusts++;
			
			cout << "Customer added." << endl << endl;
		}

		// Following Aren't Implemented
		// Check Out Book
	}

	// Write Books Back To File
	writeBooks(lib.fBooks, lib.books, lib.numBooks);

	// Write Customers Back To File
	writeCustomers(lib.fCustomers, lib.customers, lib.numCusts);

	
	return 0;
}

void printMenu()
{
	cout << "Select an Option:" << endl;
	cout << "1: List Books" << endl;
	cout << "2: Add Book to Library" << endl;
	//cout << "3: Checkout Book" << endl;
	cout << "4: List Customers" << endl;
	cout << "5: Add Customer" << endl;
	cout << "6: Exit" << endl;
}

