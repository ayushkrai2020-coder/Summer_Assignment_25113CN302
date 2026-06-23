/* Write a program to Find common characters in strings */

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
    int freq1[256] = {0};
    int freq2[256] = {0};
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    for (int i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]] = 1; 
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]] = 1;
    }
    printf("Common characters: ");
    int found = 0;
    for (int i = 0; i < 256; i++) {
        if (freq1[i] > 0 && freq2[i] > 0 && i != ' ') {
            printf("'%c' ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("None");
    }
    printf("\n");
    return 0;
}
