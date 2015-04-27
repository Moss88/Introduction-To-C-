#include "list.h"
#include<iostream>

using namespace std;


int main()
{
    List myList;
	myList.insertFront(1);
	myList.insertFront(2);
	myList.insertFront(3);
	myList.print();
	myList.removeFront();
	myList.print();
	cout << "Element at index 0: " << myList[0] << endl;
    return 0;
}
