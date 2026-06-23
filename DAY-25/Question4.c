/* Write a program to Sort words by length */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORDS 100
#define MAX_LENGTH 50

void sortWordsByLength(char words[][MAX_LENGTH], int count)
{
    char temp[MAX_LENGTH];
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strlen(words[j]) > strlen(words[j + 1]))
            {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}

int main()
{
    char input[1000];
    char words[MAX_WORDS][MAX_LENGTH];
    int wordCount = 0;
    printf("Enter a sentence: ");
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        printf("Error reading input.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';
    char *token = strtok(input, " ");
    while (token != NULL && wordCount < MAX_WORDS)
    {
        strncpy(words[wordCount], token, MAX_LENGTH - 1);
        words[wordCount][MAX_LENGTH - 1] = '\0';
        wordCount++;
        token = strtok(NULL, " ");
    }
    sortWordsByLength(words, wordCount);
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < wordCount; i++)
    {
        printf("%s (length: %zu)\n", words[i], strlen(words[i]));
    }
    return 0;
}
