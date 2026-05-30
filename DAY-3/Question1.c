/* Write a program to Check whether a number is prime */
#include <stdio.h>

int main()
{
    int n, count = 0, i;
    printf("Enter the number to check for prime:\n");
    scanf("%d", &n);
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            count++;
    }
    if (count == 0)
        printf("The given number is a prime number");
    else
        printf("The given number is not a prime number");
    return 0;
}