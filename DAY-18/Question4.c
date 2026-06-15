/* Write a program to Sort array in descending order */

#include <stdio.h>

int main()
{
    int arr[100], n, i, j, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array in descending order:\n");
    for (i = n-1; i >=0; i--)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");


    return 0;
}
