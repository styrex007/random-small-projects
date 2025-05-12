#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
    {
        srand(time(0)); // Seed for random number generation

        int secretNumber = rand() % 200 + 1; // Random number between 1 and 200
        int userGuess;

        cout << "Welcome to the Guessing Game! I have selected a number between 1 and 200, you have 10 attempts to try to guess it!" << endl;
        cout << "If you want to quit, type 0." << endl;
        
        if (userGuess == 0) {
            cout << "You have chosen to quit the game." << endl;
        }
        for (int attempts = 1; attempts <= 10; attempts++) {
            cout << "Attempt " << attempts << ": Enter your guess: ";
            cin >> userGuess;
            if (userGuess == 0) {
                cout << "You have chosen to quit the game." << endl;
                break;
            }
            if (userGuess < 1 || userGuess > 200) {
                cout << "Please enter a number between 1 and 200." << endl;
                attempts--; // Do not count this attempt
                continue; // Skip to the next iteration of the loop
            }
            if (userGuess < secretNumber) {
                cout << "Too low! Try again." << endl;
            }
            else if (userGuess > secretNumber) {
                cout << "Too high! Try again." << endl;
            }
            else {
                cout << "Congratulations! You've guessed the number!" << endl;
                break; // Exit the loop if the guess is correct
            }
        }

    }
    cout << "Thank you for playing!" << endl;
    return 0;
}
