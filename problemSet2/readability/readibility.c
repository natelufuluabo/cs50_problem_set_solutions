#include <stdio.h>
#include <string.h>

int countWord(char input[]);
int calculateAvgLettersPer100Words(int numberOfWord, char inputText[]);

int main(void)
{
    char input[50];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    return 0;
}

int countWord(char input[])
{
    char delimiter[] = " ";
    char *word;
    int wordCounter = 0;

    word = strtok(input, delimiter);

    while (word != NULL) {
        wordCounter++;
        word = strtok(NULL, delimiter);
    }

    return wordCounter;
}

int calculateAvgLettersPer100Words(int numberOfWords, char inputText[])
{
    if (numberOfWords <= 0) return 0;

    if (numberOfWords <= 100) {
        int lettersCount = 0;
        char *word;
        char *text = inputText;

        for (int i = 0; i < numberOfWords; i++) {
            // Tokenize the input text into words
            word = strtok(text, " ");

            while (word != NULL) {
                for (int j = 0, n = strlen(word); j < n; j++) {
                    if ((word[j] >= 'a' && word[j] <= 'z') || (word[j] >= 'A' && word[j] <= 'Z')) {
                        lettersCount++;
                    }
                }
                word = strtok(NULL, " ");
            }
        }

        double avgLetters = (double)lettersCount / numberOfWords;
        return (int)(avgLetters * 100);
    }
}


