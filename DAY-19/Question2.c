/* Write a program to Subtract matrices */

#include <stdio.h>

int main()
{
    int r, c;
    printf("Enter the number of rows and columns of the two matrices:\n");
    scanf("%d %d", &r, &c);
    int a[r][c];
    int b[r][c];
    printf("Enter the elements of the first matrice: \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrice: \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    int sum[r][c];
    printf("The difference of the two matrices is : \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] - b[i][j];
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}