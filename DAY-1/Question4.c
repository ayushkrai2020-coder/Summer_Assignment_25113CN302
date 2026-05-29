/* Write a program to Count digits in a number */
#include<stdio.h>

int main(){
    int n,count=0;
    printf("Enter the number to count the digits of:\n");
    scanf("%d",& n);
    if(n==0){
        count==1;
    }
    else{

        if(n<0){
            n = -n;
        }
            while(n!=0){
                n=n/10;
                count++;
            }
        }
    printf("The number of digits are %d ",count);
    

    return 0;
}