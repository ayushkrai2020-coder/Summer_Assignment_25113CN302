/* Write a program to Find maximum occurring character */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 
#define ASCII_SIZE 256 

int main() {
    char str[MAX_SIZE];
    int freq[ASCII_SIZE] = {0};
    int i, max_count;
    char max_char;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    max_count = 0;
    max_char = str[0]; 
    for (i = 0; str[i] != '\0'; i++) {
        unsigned char current_char = (unsigned char)str[i];
        if (freq[current_char] > max_count) {
            max_count = freq[current_char];
            max_char = str[i];
        }
    }
    if (max_count > 0) {
        printf("\nThe maximum occurring character is '%c' (appears %d times).\n", max_char, max_count);
    } else {
        printf("\nThe string is empty.\n");
    }
    return 0;
}
