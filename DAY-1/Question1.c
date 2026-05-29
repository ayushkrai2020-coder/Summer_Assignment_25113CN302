/*Write a program to Calculate sum of first N natural numbers*/
#include<stdio.h>

int main(){
    int i,N,sum;
    printf("Enter the number of terms to be summed:\n");
    scanf("%d",& N);
    for(i=1;i<=N;i++){
        sum=sum+i;
    }
    printf("The sum of first %d natural numbers is %d",N,sum);
    return 0;
}