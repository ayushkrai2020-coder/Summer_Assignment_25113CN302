/* Write a program to find factoriaal using functions */
#include<stdio.h>

int factorial(int n){
    int i , f=1;
    for(i=2;i<=n;i++){
        f=f*i;
    }
    return f;
}

int main(){
    int n;
    printf("Enter the value of n:\n");
    scanf("%d",& n);
    printf("The factorial of %d is %d",n,factorial(n));
    return 0;
}