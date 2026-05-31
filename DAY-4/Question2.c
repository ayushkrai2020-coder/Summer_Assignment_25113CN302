/* Write a program to Find nth Fibonacci term */
#include<stdio.h>

int main(){
     int n, temp, a = 0, b = 1;
    printf("Enter the term to be shown:\n");
    scanf("%d", &n);
    printf("The %d fibonacci term is :\n",n);
    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            temp = i;
        }
        else{
        temp = a + b;
        a = b;
        b = temp;
        }
    }
     printf("%d \n", temp);
    return 0;
}