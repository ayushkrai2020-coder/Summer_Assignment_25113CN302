/* Write a program to Remove duplicate characters */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeDuplicates(char *str) {
    bool seen[256] = { false };
    int targetIndex = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        if (!seen[ch]) {
            seen[ch] = true;
            str[targetIndex++] = str[i];
        }
    }
    str[targetIndex] = '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
        removeDuplicates(str);
        printf("String after removing duplicates: %s\n", str);
    }
    return 0;
}
