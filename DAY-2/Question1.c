/* Write a program to Find sum of digits of a number */
#include<stdio.h>

int main(){
    int n,dig,sum=0;
    printf("Enter the number:\n");
    scanf("%d",& n);
    int orig=n;
    if(orig<0){
        orig = -orig;
    }
    else{
        while(orig!=0){
            dig=orig%10;
            sum=sum+dig;
            orig=orig/10;
        }
    }
    printf("The sum of the digits of %d is %d",n,sum);
    return 0;
}