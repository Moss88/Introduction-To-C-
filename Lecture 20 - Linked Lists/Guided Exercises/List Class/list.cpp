#include "list.h"
#include <iostream>

List::List() {
	head = nullptr;
	size = 0;
}

// Inserts node at the front of the list
void List::insertFront(int num)
{
	// Dynamic Allocation on the heap of a Node
    Node *nd = new Node;
    nd->data = num;
    nd->next = head; // Sets new node to point to first node in the list
    head = nd;
	size++;
}

void List::removeFront()
{
	// Check if list is empty
	if(head == nullptr)
		return;
	
	Node* nxt = head->next; // Set node to be the second element in the list
	delete head;			// Delete first element
	head = nxt;
	size--;
}

// Prints list
void List::print()
{
	Node *nd = head;
	// Traverses each node in the list printing the data
    while(nd != NULL)
    {
        std::cout << nd->data << " ";
        nd = nd->next;
    }     
    std::cout << std::endl;
}

// Empties list by deleting all the nodes
void List::clearList()
{
	while(head != NULL)
		removeFront();
}

int List::operator[](int num)
{
	int idx = 0;
	Node *nd = head;
	// Count moves across list
	while(nd != nullptr)
	{
		if(idx == num)
			return nd->data;
		idx++;
		nd = nd->next;
	}

	// Really should throw an exception but here we will just
	// return -1, even thought this is a possible valid return
	// throw runtime_error("Index out of bounds");
	return -1;
}

int List::size() {
	return size;
}

