#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int displayMenu(int maxNumber); // Display main menu
int setMaxNumber(); // Gets max number from user and sets it
void guessingGame(int maxNumber); // Main game loop

int main(void) {
    // Set random number seed
    srand(time(NULL));
    
    // Default max number
    int maxNumber = 10;

    // Display menu (implement as function)
    //  Press 1 to play a game
    //  Press 2 to change the max number
    //  Press 3 to quit
    int selection = 0;
    while (selection != 3) {
        selection = displayMenu(maxNumber);
        switch (selection) {
            case 1: // Play game
                guessingGame(maxNumber);
                break;
            case 2: // Change max number
                maxNumber = setMaxNumber(maxNumber);
                printf("Max number set to %d.\n", maxNumber);
                break;
            case 3: // Option 3: Quit
                // Do nothing, game will quit
                break;
        }

        printf("\n");
    }

    printf("Thank you for playing!\n");
    return EXIT_SUCCESS;
}

int displayMenu(int maxNumber) {
    // Display menu
    printf("Welcome to Number Guessing Game!\n");
    printf("Options:\n");
    printf("- Press 1 to play a game\n");
    printf("- Press 2 to change the max number (current: %d)\n", maxNumber);
    printf("- Press 3 to quit\n");

    // Read user input
    int option = 0;
    while (option < 1 || option > 3) {
        printf("Make a selection: ");
        scanf("%d", &option); // Read option from user

        // Check if input is valid (falls in range 1-3)
        if (option < 1 || option > 3) {
            printf("Invalid option (must be between 1 and 3)\n");
        }
    }

    // Return option specified by user
    return option;
}

int setMaxNumber(int currentMaxNumber) {
    // Read user input
    int maxNumber = 0;
    while (maxNumber < 1) {
        printf("Input the max number you want to set (current: %d): ", currentMaxNumber);
        scanf("%d", &maxNumber); // Read max number from user

        // Check if input is valid (is not negative or zero)
        if (maxNumber < 1) {
            printf("Invalid max number (must be positive)\n");
        }
    }

    // Return new max number
    return maxNumber;
}

void guessingGame(int maxNumber) {
    // Generate random number between 1 and maxNumber that the user has to guess
    int randomNumber = rand() % maxNumber;

    // Number that the user guesses
    int userGuess = 0;

    // Loop
    while (userGuess != randomNumber) {
        // Get number from user
        printf("Guess a number between 1 and %d: ", maxNumber);
        scanf("%d", &userGuess);

        // Exit program if user entered 'q' (return -1)
        // Bug: scanf will loop forever if q is input

        // Print higher/lower if number does not equal random number
        if (userGuess < randomNumber) {
            printf("Incorrect, try again. (Hint: The number is higher than your guess)\n");
        } else if (userGuess > randomNumber) {
            printf("Incorrect, try again. (Hint: The number is lower than your guess)\n");
        }

        // Exit loop if number equals random number
    }
    printf("Correct! The number to guess was %d.\n", randomNumber);
}