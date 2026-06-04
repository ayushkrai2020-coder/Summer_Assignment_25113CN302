/* Write a program to Recursive sum of digits */
#include<stdio.h>

int sod(int n){
    if(n==0) return 0;
    return n%10+sod(n/10);
}

int main(){
    int n,sum;
    printf("Enter the number:\n");
    scanf("%d",& n);
    if(n<0) n=-n;
    sum=sod(n);
    printf("Sum of Digits of %d is %d",n,sum);
    return 0;
}