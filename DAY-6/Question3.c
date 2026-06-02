/* Write a program to Count set bits in a number */
#include <stdio.h>

int main()
{
    unsigned int num;
    int count = 0;

    printf("Enter an integer: ");
    if (scanf("%u", &num) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    while (num > 0)
    {
        num &= (num - 1);
        count++;
    }

    printf("Total set bits: %d\n", count);

    return 0;
}