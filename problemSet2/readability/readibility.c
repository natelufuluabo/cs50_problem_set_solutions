#include <stdio.h>
#include <string.h>

int countWord(char input[]);

int main(void)
{
    char input[50];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    int wordCounter = countWord(input);

    return 0;
}

int countWord(char input[])
{
    char delimiter[] = " ";
    char *word;
    int counter = 0;

    word = strtok(input, delimiter);

    int i = 0;
    while (word != NULL) {
        i++;
        counter++;
        word = strtok(NULL, delimiter);
    }

    return counter;
}