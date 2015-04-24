#include<iostream>
using std::cout;

/*
Below is an example of implementing a swap function
which can swap any two datatypes.

Interestingly C++ standard libary has a swap function
which is identical to the one below. In fact many 
C++ libary commands are implemented using templates
which makes the C++ library far more flexiable than
it's C counterpart
*/


template <typename T>
void Swap(T &a, T &b);

int main ()
{
	int x = 10, y = 20;
	char l1 = 'o', l2 = 'f';

	Swap(x, y);
	Swap(l1, l2);

	cout << "x: " << x << " y: " << y << endl;
	cout << "l1: " << l1 << " l2: " << l2 << endl;

	return 0;
}

/*
I use a generic variable T, the assumption is
that both arguments will be of the same data type
thus both are of type T.

Further we know we need a temp variable to perform a swap
therefore a temp variable is declared thats of the same generic type
*/

template <typename T>
void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}