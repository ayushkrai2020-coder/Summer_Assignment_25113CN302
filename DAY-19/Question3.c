/* Write a program to Transpose matrix */

#include <stdio.h>

int main()
{
    int r1, c1;
    printf("Enter the number of rows and columns of the first matrice:\n");
    scanf("%d %d", &r1, &c1);
    int r2, c2;
    printf("Enter the number of rows and columns of the second matrice:\n");
    scanf("%d %d", &r2, &c2);
    int a[r1][c1], b[r2][c2], s[r1][c2];
    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible");
    }
    else
    {
        printf("Enter the elements of the first matrice: \n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        printf("Enter the elements of the second matrice: \n");
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                s[i][j] = 0;
                for (int k = 0; k < c1; k++)
                {
                    s[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        printf("The multiplication of the two matrices is: \n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d\t", s[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}