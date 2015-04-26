#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node
{
	int value;
	Node *next;
};
Node* addElement(int value, Node* list);
void printList(Node* list);
Node* removeHead(Node *list);
void clearList(Node* list);

int main()
{
	Node *list = 0;

	// Add Elements to the List
	list = addElement(2, list);
	printList(list);
	list = addElement(4, list);
	printList(list);
	list = addElement(6, list);
	printList(list);
	list = addElement(8, list);
	printList(list);


	// Remove Element
	list = removeHead(list);
	printList(list);

	// Clear List to Free Memory
	clearList(list);


	return 0;
}

Node* addElement(int value, Node* list)
{
	// Adds element to the front
	Node *newElement = new Node;
	newElement->value = value;
	newElement->next = list;
	return newElement;
}

void printList(Node* list)
{
	Node *curNode = list;
	// Keep printing until no more nodes
	while(curNode != 0)
	{
		cout << setw(4) << curNode->value;
		curNode = curNode->next;
	}
	cout << endl;
}


Node* removeHead(Node *list)
{
	Node *newHead;
	// Check if List is Empty
	if(list == 0)
		return list;
	
	// Keep the next link stored
	newHead = list->next;
	// Deletes first element in the list (not all elements!)
	delete list;
	return newHead;
}

void clearList(Node* list)
{
	// Keep Removing First Element
	while(list != 0)
		list = removeHead(list);
}