/* Write a program to Find missing number in array */

#include<stdio.h>

int main(){
    int arr[] = {1,3,4,6,7,8,5,9}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = size + 1;
    int realsum = (n * (n + 1)) / 2;
    int calcsum = 0;
    for (int i = 0; i < size; i++) {
        calcsum += arr[i];
    }
    int missingno = realsum - calcsum;
    printf("The missing number is: %d\n", missingno);
    return 0;
}