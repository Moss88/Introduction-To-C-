// Guided Exercise
	// Exercise: Have the user enter in their full names
	// Parse out their name as seperate strings for the first, middle and last name.
	// It is common for people not have have a middle name. Handle the absence of the middle name

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string fullname, first, middle, last;
	getline(cin, fullname);

	int pos1 = fullname.find(" ");
	int pos2 = fullname.find(" ", pos1 + 1);
	
	if(pos2 == -1)
	{
		// No middle name so set it to be empty
		middle = "";
		// Fetch upto the first space
		first = fullname.substr(0, pos1);
		// Fetch from the first space on
		last = fullname.substr(pos1 + 1);
	}
	else
	{
		// Fetch upto the first space
		first = fullname.substr(0, pos1);
		// The difference between the index of the last and first space
		// gives the number of characters of the middle name
		middle = fullname.substr(pos1 + 1, pos2 - pos1 - 1);
		// Fetch from the last space on
		last = fullname.substr(pos2 + 1);
	}
	

	cout << "First Name: " << first << endl;
	cout << "Middle Name: " << middle << endl;
	cout << "Last Name: " << last << endl;
	return 0;
}
