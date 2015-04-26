#include<iostream>
#include<string>
using namespace std;

int main()
{
	string word, sentence;

	/*
	// Part 1: Basic IO

	// Fetching a Single Word using C++ Style Strings
	cout << "Enter a word: ";
	cin >> word;

	cout << "The word you entered is, " << word << endl << endl;

	// Must clear newline when switching between cin >> and getline
	cin.ignore();

	// Fetching multiple words
	cout << "Enter a series of words:" << endl;
	getline(cin, sentence);
	
	cout << endl << "Your string is: " << endl;
	cout << sentence << endl;
	*/

	// Part 2: String Manipulation
	string s1 = "I bought a 1976 Fiat 124 Spider. ";
	string s2 = "I have never said so many expletives.";
	string s3;

	// Detecting Length of Strings
	cout << "Length of s1: " << s1.length() << endl;
	cout << "Length of s2: " << s2.length() << endl;
	cout << endl;

	// Joining  Strings
	string finalSentence;
	finalSentence = s1 + s2;
	cout << "After Joining Two Sentences:" << endl;
	cout << finalSentence << endl;
	cout << endl;

	// Finding a substring, Finding a period
	int pos = finalSentence.find(".");
	cout << "Position of the first period: " << pos << endl;
	cout << endl;

	// Splitting a String, retrieve original sentences from finalSentence
	// Fetch first sentence based on position of the period
	string sentence1 = finalSentence.substr(0, pos + 1);
	//  With two arguements        (start Position, # of characters to extract)
	string sentence2 = finalSentence.substr(pos + 2);
	//  With one arguement                 (start position)     fetches until end of string
	cout << "Extracted Sentence 1: " << sentence1 << endl;
	cout << "Extracted Sentence 2: " << sentence2 << endl;
	cout << endl;

	// Comparing Strings
	s1 = "Neil Young";
	s2 = "Keith Richards";
	s3 = "Neil Young";
	
	cout << "Comparison of " << s1 << " with " << s2 << ": " << s1.compare(s2) << endl;
	cout << "Comparison of " << s2 << " with " << s1 << ": " << s2.compare(s1) << endl;
	cout << "Comparison of " << s1 << " with " << s3 << ": " << s1.compare(s3) << endl;

	if (s1 == s3)
		cout << s1 << " is equal to " << s3 << endl;
	else
		cout << s1 << " is not equal to " << s3 << endl;
	
	if (s1 == s2)
		cout << s1 << " is equal to " << s2 << endl;
	else
		cout << s1 << " is not equal to " << s2 << endl;
	cout << endl;

	// Part 3: String Array Notation
	// String is just an object which contains an array of characters
	// The array of characters can be accessed using array notation

	cout << "Printing using array notation: " << endl;
	for (unsigned int i = 0; i < s1.length(); i++)
		cout << s1[i];
	cout << endl;

	// Characters can be changed
	s1 = "Cool";
	cout << "Initial word: " << s1 << endl;
	s1[2] = 'l';
	s1[3] = 'd';
	cout << "Word after changes: " << s1 << endl;

	// Word of Caution: Don't access outside the length of the string. It is bad news.




	// Guided Exercise
	// Exercise: Have the user enter in their full names
	// Parse out their name as seperate strings for the first, middle and last name.
	// It is common for people not have have a middle name. Handle the absence of the middle name



	// Unguided Exercise
	// Write a function to have the user enter in a social security number with the dashes
	// Return back a function where the dashes have been removed.



	return 0;
}

