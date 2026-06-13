/* Write a program to Merge arrays */

#include<stdio.h>

int main(){
    int n1 , n2;
    printf("Enter the size of the first array:\n");
    scanf("%d", &n1);
    printf("Enter the size of the second array:\n");
    scanf("%d", &n2);
    int arr2[n2];
    int arr1[n1];
    int mer[n1+n2];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
        mer[i]=arr1[i];
    }
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
        mer[n1+i]=arr2[i];
    }
    printf("The merged array is:\n");
    for(int i=0 ; i<n1+n2 ; i++){
        printf("%d\n", mer[i]);
    }
    return 0;
}