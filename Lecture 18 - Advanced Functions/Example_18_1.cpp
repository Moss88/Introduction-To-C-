#include<iostream>
#include<string>
using namespace std;

const int capitalDiff = 'a' - 'A';
void capitalize(char *);
string capitalize(string);

int main ()
{
	string test1 = "C++ string";
	char test2[] = "C string";

	test1 = capitalize(test1);
	capitalize(test2);


	cout << test1 << endl;
	cout << test2 << endl;

	return 0;
}


string capitalize(string sentence)
{
	unsigned int i;
	for(i = 0; i < sentence.length(); i++)
	{
		if('a' <= sentence[i] && sentence[i] <= 'z')
			sentence[i] -= capitalDiff;
	}
	return sentence;
}


void capitalize(char *sentence)
{
	unsigned int i;
	for(i = 0; sentence[i] != '\0'; i++)
	{
		if('a' <= sentence[i] && sentence[i] <= 'z')
			sentence[i] -= capitalDiff;
	}
}