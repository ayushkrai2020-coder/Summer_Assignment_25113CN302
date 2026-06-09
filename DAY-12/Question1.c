/* Write a program to check for pallindrome using functions */

#include <stdio.h>

int pal(int n)
{
    int rem, rev = 0;
    int temp = n;
    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    if (temp == rev)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    printf("Enter a number :\n");
    scanf("%d", &n);
    if (pal(n))
    {
        printf("%d is a pallindrome number", n);
    }
    else
        printf("%d is not a pallindrome number", n);

    return 0;
}