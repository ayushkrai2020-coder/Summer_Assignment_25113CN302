/* Write a program to Find first non-repeating character */

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
#define ASCII_SIZE 256

int main() {
    char str[MAX_SIZE];
    int freq[ASCII_SIZE] = {0}; 
    int i;
    int found = 0;
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    str[strcspn(str, "\n")] = '\0';
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            printf("The first non-repeating character is: '%c'\n", str[i]);
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("All characters repeat or the string is empty!\n");
    }
    return 0;
}


