/* Write a program for checking for pallindrome using functions */

#include <stdio.h>
#include <math.h>

int arm(int n)
{
    int count = 0, rem, num=0;
    int n1 = n;
    int n2 = n;
    // for finding the number of terms in the number
    while (n1 != 0)
    {
        n1 = n1 / 10;
        count++;
    }
    // for finding if the number is armstrong number or not
    while (n2 != 0)
    {
        rem = n2 % 10;
        num = num + round(pow(rem, count));
        n2 = n2 / 10;
    }
    if (n == num)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    if (arm(n))
        printf("%d is an armstrong number", n);
    else
        printf("%d is not an armstrong number",n);
    return 0;
}