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

void fillColor(char board[10][10], int row, int col, char orgColor, char color)
{
    // Bounds check
    if(row >= 10 || col >= 10 || row < 0 || col < 0)
        return;

    if(board[row][col] != orgColor)
        return;

    // Set Ascii
    board[row][col] = color;

    // Visit Neighbors
    // Visit Up
    fillColor(board, row + 1, col, orgColor, color);
    // Visit Down
    fillColor(board, row - 1, col, orgColor, color);
    // Visit Left
    fillColor(board, row, col - 1, orgColor, color);
    // Visit Right
    fillColor(board, row, col + 1, orgColor, color);

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





