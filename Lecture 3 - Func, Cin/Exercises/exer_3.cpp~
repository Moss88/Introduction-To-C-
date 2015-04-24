#include<iostream>

using namespace std;

int main()
{
	// Constant Conversion Factor
	const int secInDay = 86400;
	const int secInHour = 3600;
	const int secInMinute = 60;

	long int seconds;
	int minutes, hours, days;

	// Step 1: Console input
	cout << "Enter the number of seconds: ";
	cin >> seconds;
	cout << seconds << " = ";	

	// Step 2: Calculation
	days = seconds / secInDay;		
	seconds = seconds % secInDay;	// Remove the number of days worth of seconds for next calculation

	hours = seconds / secInHour;
	seconds = seconds % secInHour;

	minutes = seconds / secInMinute;
	seconds = seconds % secInMinute;

	// Step 3: Display to Console
	cout << days << " Days " << hours <<  " Hours " << minutes << " Minutes " << seconds << " Seconds " << endl;

	return 0;
}
