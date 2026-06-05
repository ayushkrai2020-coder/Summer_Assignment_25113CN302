/* Write a program to Print repeated character pattern :
 A
 B B
 C C C 
 D D D D
 E E E E E */

#include<stdio.h>

int main(){
    int n;
    char ch;
    printf("Enter the number of rows:\n");
    scanf("%d",& n);
    ch='A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%c ",ch);
        }
        ch++;
        printf("\n");
    }
    return 0;
}