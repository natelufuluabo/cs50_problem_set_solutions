#include <stdio.h>

int main(void)
{
    int userInput;
    
    // Prompt the user to enter a number
    printf("Height: ");
    
    // Read the input from the user
    scanf("%d", &userInput);

    for (int i = 1; i <= userInput; i++)
    {
        for (int j = 0; j < userInput; j++)
        {
            if (userInput - j <= i) 
            {
                printf("#");
            }
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}