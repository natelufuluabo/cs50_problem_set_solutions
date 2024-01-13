#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calculateScore(char input[]);

int main(void)
{
    char input1[50];
    printf("Player 1: ");
    fgets(input1, sizeof(input1), stdin);
    
    char input2[50];
    printf("Player 2: ");
    fgets(input2, sizeof(input2), stdin);

    int player1Score = calculateScore(input1);
    int player2Score = calculateScore(input2);
    
    if (player1Score > player2Score)
    {
        printf("Player 1 WINS!\n");
        return 0;
    }
    else if (player1Score < player2Score)
    {
        printf("Player 2 WINS!\n");
        return 0;
    }
    else
    {
        printf("Ties!\n");
        return 0;
    }
}

int calculateScore(char input[])
{
    int sum = 0;
    int inputLength = strlen(input);
    char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    int points[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
    
    for (int i = 0; i < inputLength; i++)
    {
        if (tolower(input[i]) >= 97 && tolower(input[i]) <= 122)
        {
            for (int j = 0; j < 26; j++)
            {
                if (tolower(input[i]) == letters[j])
                {
                    sum += points[j];
                    break;
                }
            }
        }
    }

    return sum;
}