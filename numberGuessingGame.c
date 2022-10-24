#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int displayMenu(int maxNumber); // Display main menu
int setMaxNumber(); // Gets max number from user and returns it
int guessingGame(int maxNumber); // Main guessing game loop
const int DEFAULT_MAX_NUMBER = 10;

int main(void) {
    // Set random number seed
    srand(time(NULL));

    int maxNumber;
    FILE *fp = fopen("max_number.txt", "r"); // Open file stream as read-only
    if (fp != NULL) { // File exists
        if (fscanf(fp, "%d", &maxNumber) != 1) {
            // Cannot read integer from file; use default max number
            printf("Could not read a valid number from max_number.txt; using default max number.\n");
            maxNumber = DEFAULT_MAX_NUMBER;
        }
        fclose(fp); // Close file stream
    } else { // File does not exist
        maxNumber = DEFAULT_MAX_NUMBER; // Set to default max number
    }

    // Display menu (implement as function)
    //  Press 1 to play a game
    //  Press 2 to change the max number
    //  Press 3 to quit
    int selection = 0;
    while (selection != 3) {
        selection = displayMenu(maxNumber); // Display menu to user and save selection
        switch (selection) {
            case 1: // Play game
                selection = guessingGame(maxNumber);
                break;
            case 2: // Change max number
                maxNumber = setMaxNumber(maxNumber);
                printf("Max number set to %d.\n", maxNumber);

                // Save max number
                fp = fopen("max_number.txt", "w"); // Open file as write-only
                if (fp == NULL) {
                    printf("Could not open max_number.txt, not saving max number.\n");
                } else {
                    fprintf(fp, "%d", maxNumber); // Write max number to file
                    fclose(fp); // Close file stream
                }

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
        while (getchar() != '\n'); // Clears buffer to prevents printf output from looping into scanf
        printf("Input the max number you want to set (current: %d): ", currentMaxNumber);
        if (scanf("%d", &maxNumber) != 1) { // Read max number from user
            printf("Invalid number.\n"); // User did not enter a number
            continue;
        }

        // Check if input is valid (is positive)
        if (maxNumber < 1) {
            printf("Invalid max number (must be positive)\n");
        }
    }

    // Return new max number
    return maxNumber;
}

int guessingGame(int maxNumber) {
    // Generate random number between 1 and maxNumber that the user has to guess
    int randomNumber = (rand() % maxNumber) + 1;

    // Number that the user guesses
    int userGuess = 0;

    // Loop
    while (userGuess != randomNumber) {
        // Get number from user
        printf("Guess a number between 1 and %d (press 'q' to quit): ", maxNumber);
        char userInput[30]; // Stores user input as string in case user enters 'q'; converted later to an integer
        scanf("%s", &userInput);

        // Parse user input
        if (userInput[0] == 'q') { // User wants to quit
            printf("The number to guess was %d.\n", randomNumber);
            return 3; // Will exit program
        }
        userGuess = atoi(userInput); // Attempt to convert string to integer
        if (userGuess == 0) { // Invalid integer
            printf("Invalid number.\n");
            continue;
        }

        // Print higher/lower if number does not equal random number
        if (userGuess < randomNumber) {
            printf("Incorrect, try again. (Hint: The number is higher than your guess)\n");
        } else if (userGuess > randomNumber) {
            printf("Incorrect, try again. (Hint: The number is lower than your guess)\n");
        }

        // Exit loop if number equals random number
    }
    printf("Correct! The number to guess was %d.\n", randomNumber);
    return 0;
}