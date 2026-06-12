/* Write a program to find pair with given sum */

#include<stdio.h>

int main(){
    int n , found;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum;
    printf("Enter the sum: ");
    scanf("%d",& sum);
    for(int i=0 ; i<n ; i++){
        for(int j = 0 ; j< n ; j++){
            if(arr[i] + arr[j] == sum) printf("The pair that gives the sum is (%d,%d)\n",arr[i],arr[j]);
            found = 1;
        }
    }
    if(found ==0) printf("There are no pairs in the given array that give the sum %d",sum);
    
    return 0;
}