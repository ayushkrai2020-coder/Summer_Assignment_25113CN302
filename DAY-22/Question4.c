/* Write a program to Remove spaces from string */

#include <stdio.h>

void removeSpaces(char *str) {
    int readIndex = 0;
    int writeIndex = 0;
    while (str[readIndex] != '\0') {
        if (str[readIndex] != ' ') {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }
    str[writeIndex] = '\0';
}

int main() {
    char str[150];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    removeSpaces(str);
    printf("String after removing spaces: %s", str);
    return 0;
}
