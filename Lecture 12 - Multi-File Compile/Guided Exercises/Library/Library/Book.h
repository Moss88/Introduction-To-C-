#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct Book
{
	string title;
	int yearPublished;
	int pages;
	bool checkedOut;
};

bool writeBooks(string filename, Book books[], int size);
bool loadBooks(string filename, Book books[], int maxSize, int &numBooks);
void printBooks(Book books[], int size);

#endif