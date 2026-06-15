/* Write a program to Find diagonal sum */

#include <stdio.h>

int main()
{
    int matrix[10][10];
    int size, i, j;
    int principal_sum = 0;
    int secondary_sum = 0;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);
    printf("Enter the matrix elements:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < size; i++)
    {
        principal_sum += matrix[i][i];
        secondary_sum += matrix[i][size - 1 - i];
    }
    printf("\nSum of Principal Diagonal: %d", principal_sum);
    printf("\nSum of Secondary Diagonal: %d\n", secondary_sum);

    return 0;
}
