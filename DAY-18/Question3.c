/* Write a program to Binary search */

#include <stdio.h>

int main()
{
    int n, i, search, first, last, middle;
    int flag = 0;
    int array[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers (in sorted ascending order):\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter value to find: ");
    scanf("%d", &search);
    first = 0;
    last = n - 1;
    while (first <= last)
    {
        middle = first + (last - first) / 2;

        if (array[middle] == search)
        {
            printf("%d found at index %d.\n", search, middle);
            flag = 1;
            break;
        }
        else if (array[middle] < search)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }
    if (flag == 0)
    {
        printf("%d is not present in the array.\n", search);
    }

    return 0;
}
