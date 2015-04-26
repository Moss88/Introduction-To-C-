class IntArray {
public:
	IntArray(int sz = 0);
	void put(int idx, int num);
	int get(int idx);
	int length();
	void append(int num);
	void print();	
	~IntArray();

private:
	int *arr;
	int size;
};
