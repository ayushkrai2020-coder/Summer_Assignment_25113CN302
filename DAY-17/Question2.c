/* Write a program to Union of arrays */

#include <stdio.h>

int main() {
    int n1, n2;
    int i, j, flag;
    int unionSize = 0;
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter elements of the first array: \n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter elements of the second array: \n");
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int unionArr[n1 + n2];
    for(i = 0; i < n1; i++) {
        flag = 0;
        for(j = 0; j < unionSize; j++) {
            if(arr1[i] == unionArr[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            unionArr[unionSize] = arr1[i];
            unionSize++;
        }
    }
    for(i = 0; i < n2; i++) {
        flag = 0;
        for(j = 0; j < unionSize; j++) {
            if(arr2[i] == unionArr[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            unionArr[unionSize] = arr2[i];
            unionSize++;
        }
    }
    printf("\nUnion of the two arrays: ");
    for(i = 0; i < unionSize; i++) {
        printf("%d\n", unionArr[i]);
    }
    printf("\n");

    return 0;
}
