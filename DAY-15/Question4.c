/* Write a program to Move zeroes to end */

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
    printf("The new array with zeros at the end is:\n");
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            printf("%d\n",arr[i]);
        }
    }
     for(int i=0;i<n;i++){
        if(arr[i]==0){
            printf("%d\n",arr[i]);
        }
    }
    return 0;
}