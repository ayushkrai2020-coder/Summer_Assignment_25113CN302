/* Write a program to Find sum and average of array */

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
    int sum=0;
     for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    float avg=sum/n;
    printf("The sum of the array elements is %d\n",sum);
    printf("The average of the array elements is %.2f\n",avg);
    return 0;
}