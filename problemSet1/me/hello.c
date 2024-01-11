#include <stdio.h>
#include <string.h>

int main(void)
{
    char myString[20];
    
    // Prompt the user to enter a string
    printf("What is your name? ");
    
    // Read the string from the user using fgets
    fgets(myString, sizeof(myString), stdin);

    // Print the entered string
    printf("Hello, %s", myString);
}