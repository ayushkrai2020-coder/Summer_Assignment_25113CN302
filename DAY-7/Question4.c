/* Write a program to Recursive reverse number */
#include<stdio.h>

int rev(int n,int reversed){
    if(n==0) return reversed;
    int rem=n%10;
    return rev(n/10,reversed*10+rem);
}

int main(){
    int n;
    printf("Enter a number:\n");
    scanf("%d",&n);
    if(n<0) n=-n;
    int reverse=rev(n,0);
    printf("The reverse of %d is %d",n,reverse);
    return 0;
}