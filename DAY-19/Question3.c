/* Write a program to Transpose matrix */

#include <stdio.h>

int main()
{
    int r1, c1;
    printf("Enter the number of rows and columns of the matrice:\n");
    scanf("%d %d", &r1, &c1);
    int a[r1][c1];
    printf("Enter the elements of the matrice: \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {   
            printf("a[%d][%d]=",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("The transpose of the above matrix is:\n");
    for (int i = 0; i < c1; i++)
    {
        for (int j = 0; j < r1; j++)
        {
            printf("%d\t", a[j][i]);
            
        }
        printf("\n");
    }

    return 0;
}