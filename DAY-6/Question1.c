/* Write a program to Convert decimal to binary */
#include <stdio.h>

int main()
{
    int d, rem;
    long long binary = 0, place = 1;
    printf("Enter the decimal number :\n");
    scanf("%d", &d);
    int temp = d;
    if (d == 0)
        binary = 0;
    else
    {
        while (d > 0)
        {
            rem = d % 2;
            binary = binary + (rem * place);
            place = place * 10;
            d = d / 2;
        }
    }
    printf("The decimal number %d in binary is %d", d, binary);
    return 0;
}