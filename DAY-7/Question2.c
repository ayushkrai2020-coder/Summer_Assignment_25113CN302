/* Write a program to Recursive Fibonacci */
#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i;
    printf("Enter numbeer of terms for the series:\n");
    scanf("%d", &n);
    printf("The fibonacci series is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t", fibonacci(i));
    }

    return 0;
}