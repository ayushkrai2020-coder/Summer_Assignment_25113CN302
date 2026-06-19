/* Write a program to Count words in a sentence */

#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    int word_count = 0;
    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL)
    {
        return 1;
    }
    const char delimiters[] = " \t\n\r";
    char *token = strtok(sentence, delimiters);
    while (token != NULL)
    {
        word_count++;
        token = strtok(NULL, delimiters);
    }
    printf("Total number of words: %d\n", word_count);
    return 0;
}
