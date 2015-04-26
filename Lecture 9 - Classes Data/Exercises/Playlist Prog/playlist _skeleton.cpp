#include<iostream> // cout, cin, getline
#include<string>   // string
#include<fstream>  // ifstream, ofstream
#include<vector>   // vector
#include<cstdlib>  // atoi
#include<iomanip>  // setw, setfill, left
#include<sstream>  // stringstream

using namespace std;

// Structure Definition
struct Song {
	string title;
	string artist;
	int year;
	int length;
};


// Function Prototypes
// Manipulate the structure
void printPlaylist(vector<Song>);
void printSong(Song);
int findSong(string, vector<Song>);
vector<Song> deleteSong(vector<Song>);
vector<Song> addSong(vector<Song>);
void displayInfo(vector<Song>);

// Conversion between minute:second and seconds format
string secToStringFormat(int);
int stringFormatToSec(string);

// File IO
bool writeFile(string, vector<Song>);
string createFileLine(Song);
vector<Song> readFile(string);
Song parseFileLine(string);



int main()
{
	const string filepath = "playlist.txt";
	vector<Song> playlist;
	string selection;
	
	// Read from file
	playlist = readFile(filepath);


	while(selection != "exit")
	{
		// Print Menu
		cout << "Select one of the following options: " << endl;
		cout << "list: Lists the songs in the playlist" << endl;
		cout << "info: Displays information about playlist" << endl;
		cout << "add: Adds a song to the playlist" << endl;
		cout << "delete: Deletes a song from the playlist" << endl;
		cout << "exit: Exits the program" << endl;		
		cout << "select: ";
		getline(cin, selection); 
		cout << endl;

		/*	Note on getline:	
		In general: getline is safer to use then cin
		Rational: it is less prone to user error
		Example: imagine if the following code were used:

		cin >> selection;
		And the user entered "list all"

		since cin stops at white space the first cin would read list, and the next will read all
		giving your program odd behaviour. However, since getline fetches the whole line the user mistake
		will only effect the one read and no subsequent ones


		In fact, extraction operator notation '>>' used for cin is fairly dangerous when interfacing with users
		especially for non string input. However in this class we use to for convience but in practice getline
		and stringstream is a much safer method for user IO.
		*/
		

		// Select one of the functions
		if(selection == "list")
			printPlaylist(playlist);
		else if(selection == "add")
			playlist = addSong(playlist);
		else if(selection == "info")
			displayInfo(playlist);
		else if(selection == "delete")
			playlist = deleteSong(playlist);
		else if(selection != "exit")
			cout << "Invalid selection" << endl;
		cout << endl;
	}

	// Write back altered vector to the file
	if(!writeFile(filepath, playlist))
		cout << "Failed to write back file" << endl;

	return 0;
}


vector<Song> readFile(string filename)
{
    vector<Song> playlist;





    return playlist;
}

// Parses a line into seperate fields based on the delimiter ';'
// Results (hopefully) into the song structure
// Technically this isn't the safest function since there is no checking to see
// if the line follows the proper format
Song parseFileLine(string line)
{
	Song s;
	int prevIdx, curIdx;

	// Fetch Title
	curIdx = line.find(";");
	s.title = line.substr(0, curIdx);
	prevIdx = curIdx;

	// Fetch Artist Name
	curIdx = line.find(";", prevIdx + 1);
	s.artist = line.substr(prevIdx + 1, curIdx - prevIdx - 1);
	prevIdx = curIdx;

	// Fetch Year
	curIdx = line.find(";", prevIdx + 1);
	s.year = atoi(line.substr(prevIdx + 1, curIdx - prevIdx - 1).c_str());
	prevIdx = curIdx;
	
	// Fetch Length
	curIdx = line.find(";", prevIdx + 1);
	s.length = atoi(line.substr(prevIdx + 1).c_str());

	return s;
}


bool writeFile(string filename, vector<Song> playlist)
{


    return true;
}

// Function takes a Song and creates a string of the values which
// can be used for storing the song information into a file
string createFileLine(Song s)
{
	// stringstream is the easiest way to convert datatypes to string
	// prior to C++ 11
	// for an overview goto:
	// http://www.cplusplus.com/reference/sstream/stringstream/stringstream/
	// http://www.dreamincode.net/forums/topic/95826-stringstream-tutorial/
	stringstream ss;
	ss << s.title << ";" << s.artist << ";" << s.year << ";" << s.length;
	return ss.str();
}

// The function adds a song to the playlist
vector<Song> addSong(vector<Song> playlist)
{
	



    return playlist;
}

// Using the title, the functions returns the position of a song in the playlist
// Returns -1 if the song cannot be found
int findSong(string title, vector<Song> playlist)
{
	



    return -1;
}

// Using the title, the function deletes a song from the playlist
vector<Song> deleteSong(vector<Song> playlist)
{
	




    return playlist;
}

// Function prints song information to the console
void printSong(Song s)
{
	




}

// Function prints playlist to the console
void printPlaylist(vector<Song> playlist)
{





}

// Converts int seconds to minutes:seconds string
string secToStringFormat(int seconds)
{
	stringstream ss;
	int minutes;
	minutes = seconds / 60;
	seconds %= 60;
	// setfill: fills the setw width with a particular character if the field isn't fully used
	ss << setfill('0') << setw(1) << minutes << ":" << setfill('0') << setw(2) << seconds;
	return ss.str();
}

// Converts minutes:seconds string to an integer representing seconds
int stringFormatToSec(string length)
{
	int seconds = 0;	
	int colonPos = length.find(":");
	seconds += atoi(length.substr(0, colonPos).c_str()) * 60;
	seconds += atoi(length.substr(colonPos + 1).c_str());
	return seconds;
}

void displayInfo(vector<Song> playlist)
{
	int totalLength = 0, averageYear = 0, i;
	
	// Calculate Total Length and Average Year
	for(i = 0; i < playlist.size(); i++)
	{
		totalLength += playlist[i].length;
		averageYear += playlist[i].year;
	}
	
	cout << "Playlist Analytics: " << endl;
	cout << "Total Length: " << secToStringFormat(totalLength) << endl;
	cout << "Average Year of Song: " << float(averageYear)/playlist.size() << endl;
}
