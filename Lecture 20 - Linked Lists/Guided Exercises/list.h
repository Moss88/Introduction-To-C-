struct Node {
    int data;
    Node *next;
};

Node* insertFront(Node* list, int num);
Node* insertBack(Node *list, int num);

Node* removeFront(Node *list);
Node* removeBack(Node *list);
Node* removeNode(Node *list, int num);
void printList(Node *list);
Node* clearList(Node *list);
Node * createNode(int num);
