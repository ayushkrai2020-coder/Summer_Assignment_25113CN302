/* Write a program to print reversse pyramid:

 * * * * * * * * *
   * * * * * * *
     * * * * *
       * * *
         *

 */

#include <stdio.h>

int main()
{
    int n, i, j, k;
    printf("Enter the number of rows:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * i; j++)
        {
            printf(" ");
        }
        int total_stars = 2 * (n - i) - 1;
        for (int k = 0; k < total_stars; k++)
        {
            printf("*");
            if (k < total_stars - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}