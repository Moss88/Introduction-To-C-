#include <iostream>

using namespace std;

bool checkWin(char board[3][3], char player);

int main() {
	// Can modify game board to check various functions
	char board[3][3] = {{'O', ' ', 'X'},
						{'O', 'O', 'X'},
						{'X', ' ', 'X'}};


	if(checkWin(board, 'O'))
		cout << "Player O won" << endl;
	else if(checkWin(board, 'X'))
		cout << "Player X won" << endl;
	else
		cout << "No player has won" << endl;


	return 0;
}


bool checkAcross(char board[3][3], char player)
{
	bool win;
	int row, col;
	for(row = 0; row < 3; row++)
	{
		// Assume a row to be a win
		win = true;
		// Search for a player marker to disprove a win
		for(col = 0; col < 3; col++)
			if(board[row][col] != player)
				win = false;
		if(win)
			return true;
	}
	return false;
}

bool checkDown(char board[3][3], char player)
{
	bool win;
	int row, col;
	for(col = 0; col < 3; col++)
	{
		win = true;
		for(row = 0; row < 3; row++)
			if(board[row][col] != player)
				win = false;
		if(win)
			return true;
	}
	return false;
}

bool checkULDiag(char board[3][3], char player)
{
	bool win;
	int i;

	win = true;
	for(i = 0; i < 3; i++)
		if(board[i][i] != player)
			win = false;
	if(win)
		return true;

	return false;
}

bool checkLLDiag(char board[3][3], char player)
{
	bool win;
	int i;

	win = true;
	for(i = 0; i < 3; i++)
		if(board[2-i][i] != player)
			win = false;
	if(win)
		return true;

	return false;
}

// Combine all board checking functions into single
// check win function
bool checkWin(char board[3][3], char player)
{
	if(checkAcross(board, player))
		return true;
	if(checkDown(board, player))
		return true;
	if(checkULDiag(board, player))
		return true;
	if(checkLLDiag(board, player))
		return true;
	return false;
}
