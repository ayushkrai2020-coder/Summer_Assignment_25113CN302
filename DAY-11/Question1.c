/* Write a program to find sum of two numbers using functions */

#include <stdio.h>

int add(int a, int b)
{
    return (a + b);
}

int main()
{
    int a;
    printf("Enter first number:\n");
    scanf("%d", &a);
    int b;
    printf("Enter first number:\n");
    scanf("%d", &b);
    printf("The sum of %d and %d is %d", a, b, add(a,b));
    return 0;
}