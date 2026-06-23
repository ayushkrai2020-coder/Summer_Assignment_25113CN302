/* Write a program to Sort names alphabetically */

#include <stdio.h>
#include <string.h>
#define MAX_NAMES 100
#define MAX_LENGTH 50

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int n, i, j;
    printf("Enter the number of names: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_NAMES) {
        printf("Invalid number of names.\n");
        return 1;
    }
    getchar(); 
    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        fgets(names[i], MAX_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
    printf("\nAlphabetically sorted names:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}
