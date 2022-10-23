#include <stdlib.h>
#include <stdio.h>

int displayMenu(); // Display main menu
int getMaxNumber(); // Gets max number from user
void guessingGame(int maxNumber); // Main game loop

int main(void) {
    // Default max number
    int maxNumber = 10;

    // Display menu (implement as function)
    //  Press 1 to play a game
    //  Press 2 to change the max number
    //  Press 3 to quit
    int selection = displayMenu();
    while (selection != 3) {
        switch (selection) {
            case 1: // Play game
                break;
            case 2: // Change max number
                break;
            case 3: // Option 3: Quit
                break;
        }
        selection = displayMenu();
    }

    printf("Thank you for playing!\n");
}

int displayMenu() {
    // Display menu
    printf("Options:\n");
    printf("- Press 1 to play a game\n");
    printf("- Press 2 to change the max number\n");
    printf("- Press 3 to quit\n");

    // Read user input
    int option = 0;
    while (option < 1 || option > 3) {
        printf("Make a selection: ");
        scanf("%d", &option);

        // Check if input is valid (falls in range 1-3)
        if (option < 1 || option > 3) {
            printf("Invalid option (must be between 1 and 3)\n");
        }
    }

    // Return option specified by user
    return option;
}

int getMaxNumber() {
    // Read user input

    // Check if input is valid (is not negative)

    // Return max number

    return 0; // Placeholder return
}

void guessingGame(int maxNumber) {
    // Generate random number between 1 and maxNumber

    // Loop:

    //  Get number from user

    //  Exit program if user entered 'q' (return -1)

    //  Exit loop if number equals random number

    //  Print higher/lower if number does not equal random number
}