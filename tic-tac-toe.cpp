#include<iostream>
#include<string>
using namespace std;
int main() {
char board[3][3] ={
    {' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '}
};

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int row = -1;
    int col = -1;
    char winner = ' ';

    for (int i = 0; i < 9; i++) {
    //print game board
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;

        if (winner != ' ') {
            break;
        }

        //get player input
        cout << "Current player is : " << currentPlayer << endl;
        while (true) {
            cout << "Player " << currentPlayer << ", Enter row number from 0-2: ";
            cin >> row;
            cout << "Enter column number from 0-2: ";
            cin >> col;
            if (row < 0 || row > 2 || col < 0 || col > 2) {
                cout << "Invalid Input, Try again." << endl;
            }
            else if (board[row][col] != ' ') {
                cout << "Tile is full, Try again." << endl;
            }
            else {
                break;
            }
            //reset values
            row = -1;
            col = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        //check winners

        //rows-horizontal
        for (int r = 0; r < 3; r++) {
            if (board[r][0] !=' ' && board[r][0] == board[r][1] && board [r][1] == board[r][2]) {
                winner = board[r][0];
                break;
            }
        }

        //columns-vertical
        for (int c = 0; c < 3; c++) {
            if (board[0][c] !=' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
                winner = board[0][c];
                break;
            }
        }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        }
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }
    }

    if (winner != ' ') {
        cout << "Player " << winner << " wins!" << endl;
    }
    else {
        cout << "Draw!" << endl;
    }
    return 0;
}
