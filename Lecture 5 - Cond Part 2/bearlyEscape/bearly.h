#include <iostream>

using namespace std;

enum Dir {LEFT, RIGHT, UP, DOWN, NONE};

struct Coord
{
	int x, y;
	Coord();
	Coord(int x, int y);
	bool operator==(const Coord &c) const;
};

class BearlyGame 
{
	public:
		BearlyGame();			
		void turn(Dir);
		int xBear();
		int yBear();
		int xDoor();
		int yDoor();
		int xPlayer();
		int yPlayer();
		bool angryBear();
		bool isOver();
		void printBoard();

	private:
		const int boardWidth;
		const int boardHeight;
		const int bearSense;
		bool isValid(const Coord &, Dir);
		void move(Coord &, Dir);
		void delay(int);
		void moveBear();
		void clearBoard();
		char board[10][10];
		Coord bear;
		Coord door;
		Coord player;
		bool angry;
		bool end;		
};



