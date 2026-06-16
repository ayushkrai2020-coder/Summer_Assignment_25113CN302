/* Write a program to Find row-wise sum */

#include <stdio.h>

int main()
{
    int r1, c1;
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d", &r1, &c1);
    int a[r1][c1];
    int symm = 1;
    printf("Enter the elements of the square matrix: \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {   
            printf("a[%d][%d] = ",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < r1; i++)
    {   
        int sum = 0;
        for (int j = 0; j < c1; j++)
        {   
            sum = sum + a[i][j];
        }
        printf("The sum of row %d = %d\n",i+1,sum);
    }
    return 0;
}