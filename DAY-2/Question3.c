/* Write a program to Find product of digits */
#include<stdio.h>

int main(){
    int n,dig,prod=1;
    printf("Enter the number:\n");
    scanf("%d",& n);
    int orig=n;
    if(orig<0){
        orig = -orig;
    }
    else{
        while(orig!=0){
            dig=orig%10;
            prod*=dig;
            orig=orig/10;
        }
    }
    printf("The product of the digits of %d is %d",n,prod);
    return 0;
}