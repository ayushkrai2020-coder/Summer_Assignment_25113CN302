/* Write a program to Intersection of arrays */

#include <stdio.h>

int main()
{
    int arr1[100], arr2[100], intersection[100];
    int n1, n2, i, j, k;
    int k_size = 0;
    printf("Enter the number of elements for the first array: ");
    scanf("%d", &n1);
    printf("Enter %d elements for the first array:\n", n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements for the second array: ");
    scanf("%d", &n2);
    printf("Enter %d elements for the second array:\n", n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {

                int already_exists = 0;
                for (k = 0; k < k_size; k++)
                {
                    if (intersection[k] == arr1[i])
                    {
                        already_exists = 1;
                        break;
                    }
                }

                if (!already_exists)
                {
                    intersection[k_size] = arr1[i];
                    k_size++;
                }
                break;
            }
        }
    }

    if (k_size == 0)
    {
        printf("\nNo common elements found. Intersection is empty.\n");
    }
    else
    {
        printf("\nIntersection of the two arrays:\n");
        for (i = 0; i < k_size; i++)
        {
            printf("%d\n", intersection[i]);
        }
        printf("\n");
    }

    return 0;
}
