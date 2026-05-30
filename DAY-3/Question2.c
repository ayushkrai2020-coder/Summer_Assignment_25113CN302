/* Write a program to Print prime numbers in a range */
#include <stdio.h>

int main()
{
    int i, f;
    printf("Enter the starting range:\n");
    scanf("%d", &i);
    printf("Enter the ending range:\n");
    scanf("%d", &f);
    for (int j = i; j <= f; j++)
    {
        int count = 0; // resetting the count for every new number
        for (int n = 1; n <= j / 2; n++)
        {
            if (j % n == 0)
            {
                count++;
            }
        }
        if (count == 1)
        {
            printf("%d \n", j);
        }
    }
    return 0;
}