#include "intArray.h"
#include <iostream>

using std::endl;
using std::cout;
IntArray::IntArray(int sz) {
	size = sz;	
	if(size == 0)
		arr = 0;
	else
		arr = new int[size];
}

IntArray::~IntArray(){
	if(arr != 0)
		delete [] arr;
}


void IntArray::put(int idx, int num) {
	arr[idx] = num;
}

int IntArray::get(int idx) {
	return arr[idx];
}

void IntArray::append(int num) {
	// New Array
	int *tmp = new int[size + 1];

	// Copy Contents
	for(int i = 0; i < size; i++)
		tmp[i] = arr[i];

	// add item
	tmp[size] = num;

	// update size
	size++;

	// delete old array
	delete [] arr;

	// Overwrite Pointer
	arr = tmp;
}

void IntArray::print() {
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int IntArray::length() {
	return size;
}


