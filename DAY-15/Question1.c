/* Write  a program to reverse array */

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
    printf("The Reversed Array is:\n");
     for( int i = n-1 ; i>=0 ; i-- ){
        printf("%d\n",arr[i]);
    }
    return 0;
}