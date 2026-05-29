/*Write a program to Print multiplication table of a given number*/
#include<stdio.h>

int main(){
    int n,i;
    int table;
    printf("Enter the number to print the table of:\n");
    scanf("%d",& n);
    printf("The table of %d is :\n",n);
    for(i=1;i<=10;i++){
        table=i*n;
        printf("%d * %d = %d \n",n,i,table);
    }
    return 0;
}