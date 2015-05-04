#include <iostream>

void printBoard(char board[10][10])
{
    for(int i = 0; i < 10; i++)
    {
        cout << "|";
        for(int j = 0; j < 10; j++)
            cout << board[i][j];
        cout << "|" << endl;
    }
}
// This function will select a pixel for recoloring, and will also color all neighboring
// pixels of the same color
void fillColor(char board[10][10], int row, int col, char orgColor, char color)
{

}

int main()
{


    char board[10][10] = {{'G', 'G', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W'},
                          {'G', 'G', 'G', 'G', 'R', 'B', 'W', 'W', 'W', 'Y'},
                          {'G', 'G', 'G', 'R', 'R', 'B', 'W', 'W', 'Y', 'R'},
                          {'W', 'G', 'R', 'R', 'R', 'R', 'W', 'Y', 'R', 'R'},
                          {'W', 'W', 'R', 'R', 'R', 'R', 'Y', 'W', 'R', 'R'},
                          {'W', 'W', 'W', 'Y', 'Y', 'Y', 'W', 'W', 'G', 'R'},
                          {'W', 'W', 'W', 'B', 'Y', 'Y', 'G', 'G', 'G', 'R'},
                          {'W', 'W', 'B', 'B', 'Y', 'Y', 'G', 'G', 'G', 'R'},
                          {'W', 'W', 'B', 'B', 'Y', 'Y', 'G', 'Y', 'Y', 'R'},
                          {'W', 'B', 'B', 'B', 'Y', 'Y', 'G', 'Y', 'Y', 'R'}};

    cout << "Initial Board" << endl;
    printBoard(board);
    fillColor(board, 9, 2, 'B', 'G');
    cout << "After propigation:" << endl;
    printBoard(board);

    return 0;
}





