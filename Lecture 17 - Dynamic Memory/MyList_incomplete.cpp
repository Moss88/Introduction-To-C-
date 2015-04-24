#include <iostream>

using namespace std;

class MyList {
public:
	MyList();
	void addItem(string item);
	bool removeItem(string item);
	void print();
	int size();

private:
	int numItems;
	string *items;

};

MyList::MyList() {
	items = nullptr;
	numItems = 0;
}

void MyList::addItem(string item) {
	numItems++;	
	// Test for empty List
	if(items == nullptr)
		items = new string[numItems];
	else
	{
		// List isn't empty, must expand

	}

}


int main()
{
	MyList();


	return 0;
}
