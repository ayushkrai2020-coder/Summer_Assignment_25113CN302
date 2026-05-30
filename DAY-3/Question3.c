/* Write a program to Find GCD of two numbers */
#include<stdio.h>

int main(){
    int n1,n2,gcd;
    printf("Enter the two numbers :\n");
    scanf("%d %d",& n1,& n2);
    if(n1>n2){
        for(int i=1;i<=n2;i++){
            if(n1%i==0 && n2%i==0){
                gcd=i;
            }
        }
    }
    else if(n2>n1){
        for(int i=1;i<=n1;i++){
            if(n1%i==0 && n2%i==0){
                gcd=i;
            }
        }
    }
    printf("GCD of the 2 numbers is %d",gcd);
    return 0;
}