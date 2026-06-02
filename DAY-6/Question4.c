/* Write a program to Find x^n without pow() */
#include <stdio.h>

int main()
{
    int p;
    float n;
    float result = 1.0;
    printf("Enter the base number:\n");
    scanf("%f", &n);
    printf("Enter the power:\n");
    scanf("%d", &p);
    for (int i = 1; i <= p; i++)
    {
        result = n * result;
    }
    printf("The base number %.2f raised to the power %d is %.2f", n, p, result);
    return 0;
}