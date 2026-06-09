/* Write a program to Count even and odd elements */

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int arr[n];
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            even++;
        else
            odd++;
    }
    printf("The number of even elements are %d\n",even);
    printf("The number of odd elements are %d\n",odd);
    return 0;
}