#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i, vowelCnt;
	char sentence[100];
	cout << "Enter a sentence: ";
	cin.getline(sentence, 100);


	// Traverse the sentence string

	for(i = 0, vowelCnt = 0; i < 100 && sentence[i] != '\0'; i++)
	{
		// Changes from uppercase to lowercase
		if(sentence[i] >= 'A' &&  sentence[i] <= 'Z')
			sentence[i] = tolower(sentence[i]);
		

		if(sentence[i] == 'a' || sentence[i] == 'e' || 
			sentence[i] == 'i' || sentence[i] == 'o' || 
			sentence[i] == 'u')
		{
			vowelCnt++;
		}
	}


	cout << "Word is: " << sentence << endl;
	cout << "Vowel Count: " << vowelCnt << endl;

	return 0;
}