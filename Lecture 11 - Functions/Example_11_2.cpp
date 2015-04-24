#include <iostream>
#include <iomanip>
using namespace std;

void timeConversion(int &seconds, int &minutes, int &hours);


int main()
{
	int sec, min, hr;
	sec = 34445;
	timeConversion(sec, min, hr);
	cout << hr << ":" << setfill('0') << setw(2) << min << ":" << setw(2) << sec << endl;

	return 0;
}


// Pass all three by reference since all will be changed in
// the function below
void timeConversion(int &seconds, int &minutes, int &hours)
{
	hours = seconds / (3600);
	seconds %= 3600;
	minutes = seconds / 60;
	seconds %= 60;
	return;
}
