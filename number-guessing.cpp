#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void clearScreen() {
    // Clear the console screen
    #ifdef _WIN32
        system("cls"); // for Windows
    #else 
        system("clear"); // for Linux/Unix/Mac
    #endif 
}
int main() 
    {
        char playAgain;

        do {

        clearScreen(); // Clear console at the start of each round
        srand(time(0)); // Seed for random number generation

        int maxRange, maxAttempts;

        cout << "welcome to the guessing game!" << endl;
        cout << "please choose difficulty level:" << endl;
        cout << "1. easy (1-50, 10 attempts)" << endl;
        cout << "2. medium (1-100, 7 attempts)" << endl;
        cout << "3. hard (1-200, 5 attempts)" << endl;
        cout << "enter 1, 2, or 3: ";
        cout << "or enter 0 to quit the game." << endl;
        
        int difficultyLevel;
        cin >> difficultyLevel;
        
        switch (difficultyLevel) {
            case 1:
                maxRange = 50;
                maxAttempts = 10;
                break;
            case 2:
                maxRange = 100;
                maxAttempts = 7;
                break;
            case 3:
                maxRange = 200;
                maxAttempts = 5;
                break;
            default:
                cout << "Invalid choice, defaulting to medium mode." << endl;
                maxRange = 100;
                maxAttempts = 7;
        }

        int secretNumber = rand() % maxRange + 1; // Random number between 1 and maxRange
        int userGuess;
        bool guessedCorrectly = false;
        

        for (int attempts = 1; attempts <= maxAttempts; attempts++) {
            cout << "Attempt " << attempts << ": Enter your guess: ";
            cin >> userGuess;

            if (userGuess == 0) {
                cout << "You have chosen to quit the game." << endl;
                break;
            }
            
            if (userGuess < 1 || userGuess > maxRange) {
                cout << "Please enter a number between 1 and " << maxRange << endl;
                attempts--; // Do not count this attempt
                continue; // Skip to the next iteration of the loop
            }

            if (userGuess < secretNumber) {
                cout << "Too low! Try again." << endl;
            }
            else if (userGuess > secretNumber) {
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations! You've guessed the number!" << endl;
                guessedCorrectly = true;
                break; // Exit the loop if the guess is correct
            }
        }

        if (!guessedCorrectly) {
            cout << "Sorry, you've used all your attempts, the number was " << secretNumber << "." << endl;
        }
    
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!" << endl;
    return 0;
}
