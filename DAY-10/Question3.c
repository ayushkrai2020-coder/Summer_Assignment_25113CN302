/* Write a proogram to print the number pyramid:

 . . . . 1 . . . .
 . . . 1 2 1 . . .
 . . 1 2 3 2 1 . .
 . 1 2 3 4 3 2 1 .
 1 2 3 4 5 4 3 2 1

 */

#include <stdio.h>

int main()
{
    int n, i, k, j, l;
    printf("Enter the number of rows:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("%d ", k);
        }
        for (l = i - 1; l >= 1; l--)
        {
            printf("%d ", l);
        }
        printf("\n");
    }
    return 0;
}