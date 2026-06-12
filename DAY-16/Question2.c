/* Write a program to find maximum frequency element */

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int visited[n];
    int maxelement = arr[0];
    int maxcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }
        if (count > maxcount)
        {
            maxcount = count;
            maxelement = arr[i];
        }
    }
    printf("\nElement with maximum frequency: %d\n", maxelement);
    printf("It occurs %d times.\n", maxcount);

    return 0;
}