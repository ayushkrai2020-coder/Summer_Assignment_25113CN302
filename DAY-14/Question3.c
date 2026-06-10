/* Write a program to Second largest element */

#include<stdio.h>

int main(){
    int n ;
    printf("Enter the size of the array:\n");
    scanf("%d",& n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",& arr[i]);
    }
    int i , first = 0 , second = 0;
    for(i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first; 
            first = arr[i]; 
        } 
        else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }
    printf("The second largest element is %d",second);
    return 0;
}