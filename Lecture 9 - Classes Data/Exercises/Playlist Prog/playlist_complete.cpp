/*
Topics: vector, file IO, structures
Example:
The following program reads in a list of songs and their information 
which represents a playlist. The program allows for manipulation of the playlist
including adding, deleting, and printing the information. This is achieved through a
set of functions. 

The top most flow of the program is the following:
1.) Information is read into a vector (array) from a file
2.) The vector is manipulated, added, deleted, etc.
3.) At the end of the program the vector is written back to the file saving the changes

Note: This means that all manipulations to the playlist occur in the system memory
not in the file itself. The file only changes once at the end.

Rational for the Flow: In general manipulating data that is loaded into system memory
in the form of structures or arrays is significantly easier to work with than
directly manipulating the file.

Why is it Easier: A file is a stream/array of characters on a physical drive. Imagine using a typewriter
to write a novel. After having wrote the novel you find out a sentence on page 6 of 100 needs sentence 
inserted into it. This is a difficult task since all text after that position requires being shifted over
a sentence. Good luck.

Inserting data into a file is similar in that all data to the right of the insert position will 
require shifting on the physical drive. This operation is not only difficult to program but also
time intensive. Unless the file is very large, it is best to load it into system memory.

*/


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
	writeFile(filepath, playlist);

	return 0;
}


vector<Song> readFile(string filename)
{
	vector<Song> playlist;
	string line;
	Song curSong;

	// Step 1, 2: Declare and Open File
	ifstream file(filename.c_str());

	// Step 3: Check if Properly Opened
	if(!file.is_open())
	{
		cout << "Error opening playlist." << endl;
		return playlist;
	}

	// Step 4: Read in Contents
	while(file.good())
	{
		// Fetch line
		getline(file, line);
		// Empty lines at the end of a file can produce some major problems
		// Make sure the line isn't empty
		if(line != "")
		{
			// User parse function to generate the file
			curSong = parseFileLine(line);
			playlist.push_back(curSong);
		}
	}
	// Step 5: Close File
	file.close();

	// Return vector which contains all the information
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
	int i;
	// Step 1, 2: Open and Declare
	ofstream file(filename.c_str());

	// Step 3: Check if file is properly opened
	if(!file.is_open())
		return false;
	// Step 4: Write out the file
	for(i = 0; i < playlist.size(); i++)
	{
		// Use createFileLine to create a string
		file << createFileLine(playlist[i]) << endl;
	}
	// Step 5: Close File
	file.close();
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
	Song newSong;
	string tmp;

	cout << "Enter the title of the song: ";
	getline(cin, newSong.title);

	cout << "Enter the artist of the song: ";
	getline(cin, newSong.artist);

	cout << "Enter the year of the song: ";
	getline(cin, tmp);
	newSong.year = atoi(tmp.c_str());  // atoi (Ascii TO Int): converts string to int

	cout << "Enter the length of the song (min:sec): ";
	getline(cin, tmp);
	newSong.length = stringFormatToSec(tmp);

	// Adds song to the end of the playlist	
	playlist.push_back(newSong);
	cout << "Song Added." << endl;

	return playlist;
}

// Using the title, the functions returns the position of a song in the playlist
// Returns -1 if the song cannot be found
int findSong(string title, vector<Song> playlist)
{
	int i;
	for(i = 0; i < playlist.size(); i++)
	{
		if(playlist[i].title == title)
			return i;
	}	
	return -1;
}

// Using the title, the function deletes a song from the playlist
vector<Song> deleteSong(vector<Song> playlist)
{
	int loc;
	string title;

	// Fetch Title
	cout << "Name the title of the song you wish to delete: " << endl;
	cout << "Title: ";
	getline(cin, title);

	// Uses findSong function to find the index
	loc = findSong(title, playlist);
	if(loc == -1)
		cout << "Song does not exist" << endl;
	else
	{
		/*
		Erase song from vector
		playlist.begin() is an iterator, however since we dont know what 
		pointers are we shall assume the following:
		begin() is the beginning of the vector and loc is the offset
		therefore if loc is 0, the first item in the vector will be deleted.
		if loc is 3, then the beginning plus three item will be deleted (fourth item)
		*/

		playlist.erase(playlist.begin() + loc);
		cout << "Song deleted." << endl;
	}

	return playlist; 
}

// Function prints song information to the console
void printSong(Song s)
{
	// left: keyword for left justification
	// setw: sets field width
	cout << left << setw(35) << s.title << left << setw(20) << s.artist;
	cout << setw(8) << s.year << secToStringFormat(s.length) << endl;
}

// Function prints playlist to the console
void printPlaylist(vector<Song> playlist)
{
	int i;
	cout << left << setw(35) << "Title" << left << setw(20) << "Artist";
	cout << setw(8) << "Year" << "Length" << endl;
	for(i = 0; i < playlist.size(); i++)
		printSong(playlist[i]);
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
