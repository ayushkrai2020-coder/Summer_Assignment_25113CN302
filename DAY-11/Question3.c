/* Write a program to check for prime using functions */

#include<stdio.h>

int pme(int a){
    int i ;
    for(i=2;i<=a/2;i++){
        if(a%i==0){
           return 0;
        }
        else{
            return 1;
        }
    }
}

int main(){
    int a;
    printf("Enter the number:\n");
    scanf("%d",& a);
    if(pme(a)==0){
        printf("It is not prime");
    }
    else{
        printf("It is prime");
    }
    return 0;
}

