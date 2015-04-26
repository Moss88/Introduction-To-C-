#include<iostream>

using namespace std;

int main()
{
	float a, b, c, tmp;
	cout << "Enter side a then b: ";
	cin >> a >> b;
	tmp = pow(a, 2) + pow(b, 2);
	c = sqrt(tmp);

	cout << "Hypotenuse is: " << c << endl;

	return 0;
}

