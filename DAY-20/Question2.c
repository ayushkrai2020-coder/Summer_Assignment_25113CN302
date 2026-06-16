/* Write a program to check symmetric matrix */

#include <stdio.h>

int main()
{
    int r1;
    printf("Enter the number of rows and columns of the square matrix:\n");
    scanf("%d", &r1);
    int a[r1][r1];
    int symm = 1;
    printf("Enter the elements of the square matrix: \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < r1; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = i+1; j < r1; j++)
        {
            if(a[i][j]!=a[j][i]){
                symm = 0;
                break;
            }
        }
        if(symm==0){
            break;
        }
    }
    if(symm==1){
        printf("The matrix is symmetric");
    }
    else{
        printf("The matrix is not symmetric");
    }
    return 0;
}