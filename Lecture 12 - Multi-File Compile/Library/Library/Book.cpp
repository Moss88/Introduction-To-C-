#include "Book.h"

// Input: location of books file, an array of Books, maximum size of the array, number of books
// Returns false if file couldnt be opened, true if read was successful
// NumBooks contains the number of books read
bool loadBooks(string filename, Book books[], int maxSize, int &numBooks)
{
	int curIdx, prevIdx;
	ifstream file(filename);
	string line;

	if(!file.is_open())
		return false;

	numBooks = 0;
	while(file.good() && (numBooks < maxSize))
	{
		getline(file, line);

		// Fetch Title
		curIdx = line.find(";");
		books[numBooks].title = line.substr(0, curIdx);
		prevIdx = curIdx + 1;

		//Fetch Year Published
		curIdx = line.find(";", prevIdx);
		books[numBooks].yearPublished = atoi(line.substr(prevIdx, curIdx - prevIdx).c_str());
		prevIdx = curIdx + 1;

		// Fetch Page Count
		curIdx = line.find(";", prevIdx);
		books[numBooks].pages = atoi(line.substr(prevIdx, curIdx - prevIdx).c_str());

		// Set Checked Out Status
		books[numBooks].checkedOut = false;

		numBooks++;
	}

	file.close();
	return true;
}

// Prints an array of Books to a file, size is the size of the books array
// Returns true if succeeded in writing information, false otherwise
bool writeBooks(string filename, Book books[], int size)
{
	int i;
	ofstream file(filename);

	if(!file.is_open())
		return false;

	// Print Books To File
	for(i = 0; i < size; i++)
	{
		// This Ensures there is no extra new line at the end of the file
		if(i == 0)
			file << books[i].title << ";" << books[i].yearPublished << ";" << books[i].pages << ";";
		else
			file << endl << books[i].title << ";" << books[i].yearPublished << ";" << books[i].pages << ";";
	}

	file.close();
	return true;
}

// Inputs: Array of Books and Associated Size
void printBooks(Book books[], int size)
{
	int i;
	cout << left << setw(45) << "Title" << setw(8) <<"Year" << setw(5) << "Pages" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	for(i = 0; i < size; i++)
		cout << left << setw(45) << books[i].title << setw(8) << books[i].yearPublished << setw(5) << books[i].pages << endl;

	return;
}