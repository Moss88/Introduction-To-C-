#include <iostream>
using namespace std;


int main ()
{
	int kilo;
	float miles;
	
	// Simple Way
	cout << "Simple Method:" << endl;
	for(kilo = 1; kilo <= 10; kilo++)
	{
		miles = kilo * 0.621371;
		cout << kilo << " kilometers is " << miles << " miles" << endl;
	}


	// With singular on First
	cout << endl << "With first singular Method:" << endl;
	for(kilo = 1; kilo <= 10; kilo++)
	{
		miles = kilo * 0.621371;
		if(kilo == 1)
			cout << kilo << " kilometer is " << miles << " miles" << endl;
		else
			cout << kilo << " kilometers is " << miles << " miles" << endl;
	}

	// Reversed, using count down
	cout << endl << "With first singular, reversed Method:" << endl;
	for(kilo = 10; kilo >= 1; kilo--)
	{
		miles = kilo * 0.621371;
		if(kilo == 1)
			cout << kilo << " kilometer is " << miles << " miles" << endl;
		else
			cout << kilo << " kilometers is " << miles << " miles" << endl;
	}

	return 0;
	
}
	
