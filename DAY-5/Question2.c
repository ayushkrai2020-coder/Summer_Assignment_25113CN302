/* Write a program to Check strong number */
#include <stdio.h>

int main()
{
    int n, rem = 0, sum = 0;
    printf("Enter the number:\n");
    scanf("%d", &n);
    int temp = n;
    while (temp != 0)
    {
        rem = temp % 10;
        int fact = 1;
        for (int i = 2; i <= rem; i++)
        {
            fact = fact * i;
        }
        sum = sum + fact;
        temp = temp / 10;
    }
    if (n == sum)
        printf("%d is a strong number", n);
    else
        printf("%d is not a strong number", n);
    return 0;
}