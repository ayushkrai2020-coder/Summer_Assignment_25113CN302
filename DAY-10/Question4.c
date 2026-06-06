/* Write a program to print character pyramid:

 . . . . A . . . .
 . . . A B A . . .
 . . A B C B A . .
 . A B C D C B A .
 A B C D E D C B A
 
 */

#include <stdio.h>

int main()
{
    int n, i;
    char k, j, l;
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
            printf("%c ", 64+k);
        }
        for (l = i - 1; l >= 1; l--)
        {
            printf("%c ", 64+l);
        }
        printf("\n");
    }
    return 0;
}