#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node *next;
};

void printList(Node* list);

int main() {
    ////////////////////////////////////////////////
    /// Adding Nodes to a List
    ///////////////////////////////////////////////


    Node *head;
    head = new Node;       // Creates new node
    head->data = 4;        // puts 4 in node
    // end of list should always be pointing to null
    // without null, there is no way to determine when the
    // list ends since all other addresses are valid places
    // for the node
    head->next = nullptr;


    // Right now the list is of size 1, [4]
    // Lets add a node in front
    Node *tmp = new Node; // Creates another node
    tmp->data = 2;        // Put 2 in node
    tmp->next = head;     // Points tmp to head creating [2 4]
    // Prior to this example, head was no longer pointing to the beginning
    // of the list, tmp was. so we update it
    head = tmp;



    // Lets print the list [2, 4]
    cout << "Added 2, 4" << endl;
    cout << head->data << " " << head->next->data << endl;


    // Right now the list is of size 2, [2 4]
    // Lets add a node with value 3 in the middle of 2, 4
    tmp = new Node;         // Creates another node, but reuses tmp pointer
    tmp->data = 3;          // Put 3 in node

    // head->next points to the last node of the list right now
    // since tmp is in the middle, it should point to the last node
    tmp->next = head->next;

    // head->next is still pointing to the end of the list, so
    // it is updated to point to the middle node
    head->next = tmp;

    // Lets Print the list [2, 3, 4]
    cout << "Added 3" << endl;
    cout << head->data << " " << head->next->data << " " << head->next->next->data << endl;


    // It should be noted, that the data numbers
    // do not set the order of the nodes, only the
    // way they are inserted


    //////////////////////////////////////////////////////
    // Generically Printing a List
    ////////////////////////////////////////////////////
    cout << "Generic Print" << endl;
    tmp = head;                     // Use tmp as a pointer to the current node
    while(tmp != nullptr)           // the last's node's next field should be nullptr
    {
        cout << tmp->data << " ";   // print current node's data
        tmp = tmp->next;            // Move to next node
    }
    cout << endl;


    /////////////////////////////////////////////////////////
    // Removing A Node
    ////////////////////////////////////////////////////////

    // Lets Start by remove the front node 2 in [2, 3, 4]
    // We cannot immediatly call delete on the head node, because we will
    // lose the link to the second node. So we make a copy of this reference.
    tmp = head->next;
    delete head;        // Now we delete this node
    head = tmp;         // Set head to the second node

    // List is now [3, 4];
    cout << "Remove 2" << endl;
    printList(head);


    // Quickly add back the two
    tmp = new Node;
    tmp->data = 2;
    tmp->next = head;
    head = tmp;

    // Lets Remove the middle node, 3, from [2, 3, 4]
    // If I remove the middle node, immediatly I will lose the link to the last
    // element, 4, therefore i need to save a reference to it first
    tmp = head->next->next;     // Fetches last
    delete head->next;          // Deletes middle element
    head->next = tmp;           // head node points to older middle node, change to point to end

    // List is now [2, 4];
    cout << "Added 2, Removed 3" << endl;
    printList(head);

    return 0;
}


// Taken from example in main
void printList(Node* list) {
    while(list != nullptr)
    {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}


