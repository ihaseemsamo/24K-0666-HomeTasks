#include <iostream>
using namespace std;

int secret;
int totalPlayers;

void guessNumber(int playerTurn) {
    int guess;
    cout << "Player " << playerTurn << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == secret) {
        cout << "?? Congratulations! Player " << playerTurn 
             << " guessed the correct number " << secret << "!\n";
        return;
    } 
    else if (guess < secret) {
        cout << "Too low! Try again.\n";
    } 
    else {
        cout << "Too high! Try again.\n";
    }

    int nextPlayer = (playerTurn % totalPlayers) + 1;
    guessNumber(nextPlayer);
}

int main() {
    cout << "Enter the secret number (1-100): ";
    cin >> secret;

    cout << "Enter number of players: ";
    cin >> totalPlayers;

    cout << "\n--- Number Guessing Game Started ---\n";
    guessNumber(1);

    return 0;
}
