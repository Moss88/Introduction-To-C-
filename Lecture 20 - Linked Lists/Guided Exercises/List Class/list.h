struct Node {
    int data;
    Node *next;
};

class List {
public:
	List();
	void insertFront(int num);
	void removeFront();
	void print();
	void clearList();
	int operator[](int num);
private:
	int size;
	Node *head;
};
