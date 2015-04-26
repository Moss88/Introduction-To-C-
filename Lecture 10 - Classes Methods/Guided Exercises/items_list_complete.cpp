#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class MyList {

	public:
		MyList();
		bool addItem(string item);
		bool removeItem(string item);				
		void print();
		bool save(string filepath);
		bool load(string filepath);

	private:
		string items[1000];
		int numItems;

};

MyList::MyList() {
	numItems = 0;
}

void MyList::print() {
	int i;
	for(i = 0; i < numItems; i++)
		cout << items[i] << endl;
}

bool MyList::addItem(string item) {
	if(numItems >= 1000)
		return false;
	items[numItems] = item;
	numItems++;
	return true;
}

bool MyList::removeItem(string item) {
	// Find Item
	int i, loc;
	for(loc = 0; loc < numItems; loc++)
		if(items[loc] == item)
			break;
	// Check to see if item was found
	if(loc == 1000)
		return false;

	// Shift all items after the deleted item back one position
	numItems--;
	for(i = loc; i < numItems; i++)
		items[i] = items[i+1];

	return true;	
}


bool MyList::save(string filepath) {
	// Step 1: Declare Stream	
	ofstream outFile;
	// Step 2: Open File
	outFile.open(filepath.c_str());
	// Step 3: Check for Success
	if(!outFile.is_open())
		return false;
	// Step 4: Output File
	for(int i = 0; i < numItems; i++)
		outFile << items[i] << endl;
	// Step 5: close file
	outFile.close();
	return true;
}

bool MyList::load(string filepath) {
	// Step 1: Declare Stream	
	ifstream inFile;

	// Step 2: Open File
	inFile.open(filepath.c_str());

	// Step 3: Check for Success
	if(!inFile.is_open())
		return false;

	// Step 4: Output File
	numItems = 0; // Clear list
	while(inFile.good())
	{
		string buffer;
		getline(inFile, buffer);
		if(buffer.empty())
			continue;

		items[numItems] = buffer;
		numItems++;
	}
	
	// Step 5: close file
	inFile.close();
	return true;
}


int main(){
	MyList lst;

	string selection, item;
	
	while(selection != "Exit")
	{
		cout << "Select one of the following:" << endl;
		cout << "Print: to print list" << endl;
		cout << "Add: to add item" << endl;
		cout << "Remove: to remove item" << endl;
		cout << "Save: to same items to file" << endl;
		cout << "Load: to load list from file" << endl;
		cout << "Exit: to exit file" << endl;
		cout << "Selection: ";		
		getline(cin, selection);
		cout << endl;
		if(selection == "Add")
		{
			cout << "Item to add: ";
			getline(cin, item);
			lst.addItem(item);
		}
		else if(selection == "Remove")
		{
			cout << "Item to remove: ";
			getline(cin, item);
			lst.removeItem(item);
		}
		else if(selection == "Print")
			lst.print();
		else if(selection == "Save")
		{
			string filepath;
			cout << "Filepath: ";
			getline(cin, filepath);
			if(lst.save(filepath))
				cout << "Successfully Saved." << endl;
			else
				cout << "Failed to Save File." << endl;
			
		}
		else if(selection == "Load")
		{
			string filepath;
			cout << "Filepath: ";
			getline(cin, filepath);
			if(lst.load(filepath))
				cout << "Successfully Loaded." << endl;
			else
				cout << "Failed to Load File." << endl;
		}
		cout << endl;

	}




	return 0;
}
