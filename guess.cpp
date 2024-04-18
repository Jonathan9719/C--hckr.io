#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Main Task: A number game of guessing the random number between 1 and 100
// Improvement: Keep track of guesses and print out the tries at the end
int main() {
    // initialize random seed
    srand(static_cast<unsigned int>(time(0))); 

    // generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int tries = 0;

    // prompt
    cout << "I have chosen a number between 1 and 100.\n";
    cout << "Can you guess it?\n";

    // Loop with hints until user guesses number
    while (guess != secretNumber) {
        cout <<  "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber)
        {
            cout << "Too high! Try again.\n";
            tries++;
        }
        else if (guess < secretNumber) 
        {
            cout << "Too low! Try again.\n";
            tries++;
        }
        else 
        {
            cout << "Congratulations, you are correct! You lucky dog it only took you " << tries << " tries!\n";
        }
    }
    
    return 0;
}