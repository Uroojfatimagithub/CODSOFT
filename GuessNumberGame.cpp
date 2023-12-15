#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int secretNumber = (std::rand() % 100) + 1;

    std::cout << "Welcome to the Guess the Number game!\n";
    std::cout << "I have selected a random number between 1 and 100. Try to guess it!\n";

    int userGuess;
    int attempts = 0;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts!\n";
            break;  // Break out of the loop when the correct number is guessed
        }
    }

    return 0;
}
