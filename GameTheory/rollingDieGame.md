#include <iostream>
#include <ctime>

using namespace std;

int main()
{

    // Generate a random number between 1 and 6
    int randomNumber = rand() % 6 + 1;

    int guess;
    cout << "Welcome to the Dice Rolling Game!" << endl;
    cout << "Guess the number (between 1 and 6) rolled on the dice: ";
    cin >> guess;

    // Check if the guess is valid
    if (guess < 1 || guess > 6)
    {
        cout << "Invalid guess. Please guess a number between 1 and 6." << endl;
        return 1; // Exit with an error code
    }

    
    cout << "You rolled a " << randomNumber << "." << endl;

    if (guess == randomNumber)
    {
        cout << "Congratulations! You guessed correctly!" << endl;
    }
    else
    {
        cout << "Sorry, you guessed wrong. Better luck next time!" << endl;
    }

    return 0;
}