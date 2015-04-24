#include<iostream>
#include<string>
using namespace std;

int main()
{
	unsigned int i;
	string w1, w2;
	cout << "Enter a word: ";
	cin >> w1;
	cout << "Enter another word: ";
	cin >> w2;

	
	w1.append(" "); // Add space to end of word 1
	w1.append(w2);  // Add w2 to end of w1
	w1.append("."); // Add period to end of word

	// Captilize first Letter
	if('a' <= w1[0] && w1[0] <= 'z')
			w1[0] = toupper(w1[0]);

	// Prevent overflow and going past end of string
	for(i = 1; i < w1.size(); i++)
	{
		// to lowercase using ascii table numbers
		if('A' <= w1[i] && w1[i] <= 'Z')
			w1[i] = tolower(w1[i]);
	}

	cout << "Sentence is: " << w1 << endl;

	return 0;
}