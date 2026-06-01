/* Write a program to Print factors of a number */
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number:\n");
    scanf("%d", &n);
    printf("The prime factors of %d are:\n", n);
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            printf("%d \n", i);
    }
    return 0;
}