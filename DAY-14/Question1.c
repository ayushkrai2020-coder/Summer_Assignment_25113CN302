/* Write a program to Linear search */

#include<stdio.h>

int main(){
      int n , finding=0;
    printf("Enter the size of the array:\n");
    scanf("%d",& n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",& arr[i]);
    }
    printf("Enter the element to be searched: ");
    int search;
    scanf("%d",& search);
     for(int i=0;i<n;i++){
       if(search==arr[i]){
        printf("Element found in the array");
        finding=1;
        break;
       }
    }
    if(finding==0){
        printf("Element not found in the array");
    }
    return 0;
}