#include<iostream>
using namespace std;

int main()
{
	float numTrees;
	const float reforestRate = .02;
	int curYear;

	// Step 1: User Input
	cout << "Enter in the initial number of trees: ";
	cin >> numTrees;

	// Step 2: Calculation
	curYear = 0;
	while(numTrees < 1000)
	{
		numTrees = numTrees + numTrees * reforestRate;
		curYear++;
	}
	
	// Step 3: Feedback
	cout << "It took " << curYear << " years to reach 1000 trees." << endl;
	return 0;
}
