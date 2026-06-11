/* Write a program to Rotate array right */

#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d",& n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",& arr[i]);
    }
    printf("The Original Array is:\n");
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    printf("The Rotated Array (Right) is:\n");
     for(  int i=n-1;i>=0; i--){
        printf("%d ",arr[i]);
    }
    return 0;
}