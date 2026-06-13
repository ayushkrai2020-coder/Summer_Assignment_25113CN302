/* Write a program to find common elements */

#include <stdio.h>

int main() {
    int n1, n2;
    int i, j, k;
    int isDuplicate;
    printf("Enter the number of elements for the first array: ");
    if (scanf("%d", &n1) != 1 || n1 <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    int arr1[n1];
    printf("Enter %d elements for the first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements for the second array: ");
    if (scanf("%d", &n2) != 1 || n2 <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    int arr2[n2];
    printf("Enter %d elements for the second array:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("\nCommon elements are: ");
    int foundAny = 0;

    for (i = 0; i < n1; i++) {
        isDuplicate = 0;
        for (k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                isDuplicate = 1;
                break;
            }
        }
    
        if (!isDuplicate) {
            for (j = 0; j < n2; j++) {
                if (arr1[i] == arr2[j]) {
                    printf("%d\n", arr1[i]);
                    foundAny = 1;
                    break; 
                }
            }
        }
    }

    if (!foundAny) {
        printf("None");
    }

    return 0;
}
