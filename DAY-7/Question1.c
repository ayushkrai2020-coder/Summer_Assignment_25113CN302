/* Write a program to Recursive factorial */
#include <stdio.h>

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    int fact = factorial(n);
    printf("The  factorial of %d is %d", n , fact);
    return 0;
}