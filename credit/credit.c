#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* verityCardType(long userInput);
long get_long(void);

int main(void)
{
    long userInput = get_long();

    const char* cardType = verifyCardType(userInput); 

    // Print the result
    printf("Card Type: %s\n", cardType);

    return 0;
}

const char* verifyCardType(long userInput)
{
    int maxDigits = snprintf(NULL, 0, "%ld", userInput);
    
    // Allocate a buffer to hold the string representation
    char buffer[maxDigits + 1];  // +1 for the null terminator

    // Convert the long to a string
    sprintf(buffer, "%ld", userInput);

    // Verify first digit of the number
    char firstDigit = buffer[0];
    switch (firstDigit) {
        case '3':
            return "AMEX";
        case '4':
            return "VISA";
        case '5':
            return "MASTERCARD";
        default:
            return "INVALID";
    }
}

long get_long(void)
{
    long userInput;
    int validInput;

    do 
    {
        // Prompt the user to enter a number
        printf("Number: ");

        // Read the input from the user
        validInput = scanf("%ld", &userInput);

        // Clear the input buffer in case of non-numeric input
        while (getchar() != '\n');

        // Check if the input was valid
        if (!validInput) {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }
    while (!validInput);

    return userInput;
}