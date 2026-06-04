/* Write a program to print half pyramid pattern */
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of rows of the pattern:\n");
    scanf("%d",& n);
    printf("The half pyramid pattern is:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}