/* Write a program to Find first repeating character */

#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256 

int main() {
    char str[1000];
    int count[MAX_CHAR] = {0};
    char first_repeating = '\0';
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i]; 
        count[ch]++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        if (count[ch] > 1) {
            first_repeating = str[i];
            break;
        }
    }
    if (first_repeating != '\0') {
        printf("The first repeating character is: '%c'\n", first_repeating);
    } else {
        printf("No repeating characters found.\n");
    }
    return 0;
}
