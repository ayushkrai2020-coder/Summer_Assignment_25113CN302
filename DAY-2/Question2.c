/* Write a program to Reverse a number */
#include<stdio.h>

int main(){
    int n,rev=0,dig;
    printf("Enter the numkbeer to find the reverse of:\n");
    scanf("%d",& n);
    int orig=n;
    if(orig<0){
        orig = -orig;
    }
    else{
        while(orig!=0){
            dig=orig%10;
            rev=rev*10+dig;
            orig=orig/10;
        }
    printf("The reverse of %d is %d",n,rev);
    }
    return 0;
}