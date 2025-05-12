#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

bool isWinningMove(char b[3][3], int r, int c, char symbol) {
    char temp = b[r][c];
    b[r][c] = symbol;

    
    bool win = (
        (b[r][0] == symbol && b[r][1] == symbol && b[r][2] == symbol) || // check row
        (b[0][c] == symbol && b[1][c] == symbol && b[2][c] == symbol) || // check column
        (b[0][0] == symbol && b[1][1] == symbol && b[2][2] == symbol) || // check diagonal
        (b[2][0] == symbol && b[1][1] == symbol && b[0][2] == symbol) // check anti diagonal
    );

    b[r][c] = temp; // restore original state
    return win;
}


void computerMove(char b[3][3]) {
    // 1. try to win
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (b[r][c] == ' ' && isWinningMove(b, r, c, 'O')) {
                b[r][c] = 'O'; // make the winning move
                return;
                }
            }
        }
    // 2. block player
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (b[r][c] == ' ' && isWinningMove(b, r, c, 'X')) {
                b[r][c] = 'O'; // block the player
                return;
            }
        }
    }

    // 3. take center if available 
    if (b[1][1] == ' ') {
        b[1][1] = 'O';
        return;
    }

    // 4. take a corner if available 
    int corners[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (int i = 0; i < 4; i++) {
        int r = corners[i][0];
        int c = corners[i][1];
        if (b[r][c] == ' ') {
            b[r][c] = 'O';
            return;
        }
    }

    // 5. take any open
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (b[r][c] == ' ') {
                b[r][c] = 'O'; // take any open space
                return;
            }
        }
    }
}

bool checkWinner (char b[3][3], char& winner) {
    // Check rows
    for (int r = 0; r < 3; r++) {
        if (b[r][0] != ' ' && b[r][0] == b[r][1] && b[r][1] == b[r][2]) {
            winner = b[r][0];
            return true;
        }
    } 
    // Check columns
    for (int c = 0; c < 3; c++) {
        if (b[0][c] != ' ' && b[0][c] == b[1][c] && b[1][c] == b[2][c]) {
            winner = b[0][c];
            return true;
        }
    }
    // Check diagonals
    if (b[0][0] != ' ' && b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        winner = b[0][0];
        return true;
    }
    // Check anti-diagonal
    if (b[0][2] != ' ' && b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        winner = b[0][2];
        return true;
    }

    return false; // no winner
}

void printBoard(char b[3][3]) {
    cout << "   |   |   " << endl;
    cout << " " << b[0][0] << " | " << b[0][1] << " | " << b[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << b[1][0] << " | " << b[1][1] << " | " << b[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << b[2][0] << " | " << b[2][1] << " | " << b[2][2] << endl;
    cout << "   |   |   " << endl;
}

int main(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    int playerWins = 0;
    int computerWins = 0;
    int draws = 0;
    const char player = 'X';
    const char computer = 'O';
    char board[3][3];
    char playAgain;


    do {
        // reset board
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                board[r][c] = ' ';

    char winner = ' ';
    int moves = 0;

    srand(time(0)); // seed for random number generation

    bool playerStarts = rand() % 2 == 0;
    cout << (playerStarts ? "You go first.\n" : "Computer goes first.\n");
    
    if (!playerStarts) {  // If computer starts, make the first move.
        cout << "Computer's turn (O).\n";
        computerMove(board); // Let the computer take its first turn.
        moves++; // Increment moves since computer made its move
    }


    while (moves<9) {
        printBoard(board);

        // Player move
        int row, col;
        while (true) {
            cout << "Your turn (X). Enter row (0-2): ";
            cin >> row;
            cout << "Enter column (0-2): ";
            cin >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2) {
                cout << "Invalid move, try again." << endl;
            } else if(board[row][col] != ' ') {
                cout << "Cell taken, try again." << endl;
            } else {
                break;
            }
        }
        board[row][col] = player;
        moves++;
        if (checkWinner(board, winner)) break;
        if (moves == 9) break;

        // computer move
        cout << "Computer's turn (O)." << endl;
        computerMove(board);
        moves++;
        if (checkWinner(board, winner)) break;
    }

    printBoard(board);

    if (winner == player) {
        cout << "You win!\n";
        playerWins++;
    }
    else if (winner == computer) {
        cout << "Computer wins!\n";
        computerWins++;
    }
    else {
        cout << "It's a draw!\n";
        draws++;
    }
    cout << "\nSCOREBOARD:\n";
    cout << "You: " << playerWins << " | Computer: " << computerWins << " | Draws: " << draws << "\n";


    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
