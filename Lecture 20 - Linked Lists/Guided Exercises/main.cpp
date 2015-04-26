#include "list.h"
#include<iostream>

using namespace std;


int main()
{
    Node *list = NULL;
	cout << "Inserting at the back of the list" << endl;
    list = insertBack(list, 1);
	printList(list);
    list = insertBack(list, 2);
	printList(list);
	list = insertBack(list, 3);
	printList(list);	
	cout << "Inserting at the front of the list" << endl;
	list = insertFront(list, 4);
	printList(list);    
	list = insertFront(list, 5);
	printList(list);	
	list = insertFront(list, 6);
    printList(list);

	cout << "Removing from the back of the list" << endl;
	list = removeBack(list);
	printList(list);
	list = removeBack(list);
	printList(list);

	cout << "Removing from the front of the list" << endl;
	list = removeFront(list);
	printList(list);
	list = removeFront(list);
	printList(list);

	list = clearList(list);
    return 0;
}
