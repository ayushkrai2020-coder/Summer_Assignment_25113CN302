/* Write a program to Check whether a number is palindrome */
#include<stdio.h>

int main(){
    int n,rev=0,dig;
    printf("Enter the number :\n");
    scanf("%d",& n);
    int orig=n;
    while(n!=0){
        dig=n%10;
        rev=rev*10+dig;
        n=n/10;
    }
    if(orig==rev){
        printf("The number is a pallindrome");
    }
    else{
        printf("The number is not a pallindrome");
    }
    return 0;
}