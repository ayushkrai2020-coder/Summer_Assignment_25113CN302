/* write a program to find maximum using functions */

#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int a, b;
    printf("Enter 1st number :\n");
    scanf("%d", &a);
    printf("Enter 2nd number :\n");
    scanf("%d", &b);
    printf("The maximum number between %d and %d is %d", a, b, max(a,b));
    return 0;
}