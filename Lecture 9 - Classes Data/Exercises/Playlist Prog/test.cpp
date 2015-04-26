#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream file("playlist.txt");
	string line, title, artist;
	int loc;
	
	if(!file.is_open())
	{
		cout << "Error" << endl;
		return 0;
	}


	while(file.good())
	{
		getline(file, line);
		loc = line.find(";");
		title = line.substr(0, loc);
		
		prevLoc = loc;
		loc = line.find(loc, ";");


		cout << title << endl;		


	}

	file.close();


	return 0;
}
