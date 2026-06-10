/* Write a program to Find duplicates in array */

#include <stdio.h>

int main() {
    int n ;
    int found_duplicate = 0;
    printf("Enter the size of the array:\n");
    scanf("%d",& n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",& arr[i]);
    }
    printf("Duplicate elements in the array are: \n");
    for (int i = 0; i < n; i++) {
        int already_counted = 0;
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                already_counted = 1;
                break;
            }
        }
        if (already_counted) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("%d \n", arr[i]);
                found_duplicate = 1;
                break; 
            }
        }
    }

    if (!found_duplicate) {
        printf("None");
    }
    printf("\n");

    return 0;
}
