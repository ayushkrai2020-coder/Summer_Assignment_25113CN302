/* Write a program to Find factorial of a number */
#include<stdio.h>

int main(){
    int n,i;
    int fact=1;
    printf("Enter the number to find the factorial of :\n");
    scanf("%d",& n);
    for(i=1;i<=n;i++){
        fact=fact*i;
    }
    printf("The factorial of %d is %d",n,fact);
    return 0;
}