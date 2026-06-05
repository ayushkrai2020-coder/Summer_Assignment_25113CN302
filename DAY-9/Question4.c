/* Write a program to print hollow square pattern:

 * * * * *
 *       *
 *       *
 *       *
 * * * * *

 */

#include <stdio.h>

int main()
{
    int r, c;
    printf("Enter number of rows:\n");
    scanf("%d", &r);
    printf("Enter number of columns:\n");
    scanf("%d", &c);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i == 1 || i == r || j == 1 || j == c)
            {
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}