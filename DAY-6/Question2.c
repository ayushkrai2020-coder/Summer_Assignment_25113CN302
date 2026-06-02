/* Write a program to Convert binary to decimal */
#include<stdio.h>

int main(){
    long long binary;
    int d=0 , base=1 , rem ;
    printf("Enter the binary number :\n");
    scanf("%lld",& binary);
    long long temp=binary;
    while(temp>0){
        rem=temp%10;
        d=d+(rem*base);
        base=base*2;
        temp=temp/10; 
    }
    printf("The binary number %lld in decimal is %d",binary,d);

    return 0;
}