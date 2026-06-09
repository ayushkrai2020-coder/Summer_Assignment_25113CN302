/* Write a program for fibonacci using functions */

#include<stdio.h>

void fib(int n){
    int a=0,b=1,temp;
    printf("The Fibonacci Series is:\n");
    for(int i=1;i<=n;i++){
        printf("%d\n",a);
        temp=a+b;
        a=b;
        b=temp;
    }
    return;
}

int main(){
    int n;
    printf("Enter the number of terms:\n");
    scanf("%d",& n);
    fib(n);
    return 0;
}