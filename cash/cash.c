#include <stdio.h>

int main(void)
{
    int userInput;

    do 
    {
        // Prompt the user to enter a number
        printf("Change owed: ");
        
        // Read the input from the user
        scanf("%d", &userInput);
    }
    while (userInput < 0);
    
    int counter = 0;
    while (userInput > 0)
    {
        while (userInput - 25 >= 0) 
        {
            counter++;
            userInput -= 25;
        }
        while (userInput - 10 >= 0) 
        {
            counter++;
            userInput -= 10;
        }
        while (userInput - 5 >= 0) 
        {
            counter++;
            userInput -= 5;
        }
        while (userInput - 1 >= 0) 
        {
            counter++;
            userInput -= 1;
        }
    }
    printf("%i\n", counter);
}