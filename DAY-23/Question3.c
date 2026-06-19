/* Write a program to Check anagram strings */

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int checkAnagram(char *str1, char *str2) {
    int count[256] = {0};
    int i;
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    for (i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }
    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    if (checkAnagram(str1, str2)) {
        printf("\n\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\n\"%s\" and \"%s\" are NOT anagrams.\n", str1, str2);
    }
    return 0;
}
