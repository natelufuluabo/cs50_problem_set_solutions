#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const char* verifyUserInput(long userInput);
const char* convertToString(long userInput);
long get_long(void);

int main(void)
{
    int sumWithMuliplication = 0;
    int sumWithoutMuliplication = 0;
    long userInput = get_long();

    const char* cardType = verifyUserInput(userInput); 
    const char* invalidStr = "INVALID";

    if (cardType == invalidStr)
    {
        printf("Card Type: %s\n", cardType);
        return 0;
    }

    const char* cardNumberConverted = convertToString(userInput);
    int digitLength = strlen(cardNumberConverted);
    printf("\n");
    for (int i = 0; i < digitLength; i++)
    {
        if (i % 2 != 0)
        {
            sumWithoutMuliplication += atoi(&cardNumberConverted[i]);
        }
        else
        {
            int product = (atoi(&cardNumberConverted[i + 1]) * 2);
            const char* productString = convertToString(product);
            int productStringLength = strlen(productString);
            if (productStringLength > 1)
            {
                for (int j = 0; j < productStringLength; j++)
                {
                    sumWithMuliplication += (atoi(&productString[i]));
                }
            } 
            else
            {
                sumWithMuliplication += product;
            }
        }
        
    }

    if ((sumWithMuliplication + sumWithoutMuliplication) % 10 == 0)
    {
        printf("Card Type: %s\n", cardType);
        return 0;
    }

    printf("Card Type: INVALID\n");
    return 0;
}

const char* convertToString(long userInput) 
{
    int maxDigits = snprintf(NULL, 0, "%ld", userInput);
    
    // Allocate a buffer to hold the string representation
    char buffer[maxDigits + 1];  // +1 for the null terminator

    // Convert the long to a string
    sprintf(buffer, "%ld", userInput);

    const char* text = buffer;
    return text;
}

const char* verifyUserInput(long userInput)
{
    const char* buffer = convertToString(userInput);

    int digitLength = strlen(buffer);

    if (!(digitLength >= 13 && digitLength <= 17)) {
        return "INVALID";
    }

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