#include<iostream>

using namespace std;

int main()
{
	float a, b, c;
	cout << "Enter side a then b: ";
	cin >> a >> b;
	c = sqrt(pow(a, 2) + pow(b, 2));

	cout << "Hypotenuse is: " << c << endl;

	return 0;
}

