/* Write a program to Find largest and smallest element */

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
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<n;i++){
       if(arr[i]<min){
        min=arr[i];
       } 
       if(arr[i]>max){
        max=arr[i];
       } 
    }
    printf("The smallest element of the array is %d\n",min);
    printf("The largest element of the array is %d",max);
    return 0;
}