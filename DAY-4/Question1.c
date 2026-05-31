/* Write a program to Generate Fibonacci series */
#include <stdio.h>

int main()
{
    int n, temp, a = 0, b = 1;
    printf("Enter the number of terms to be shown:\n");
    scanf("%d", &n);
    printf("The fibonacci series is :\n");
    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            temp = i;
        }
        else{
        temp = a + b;
        a = b;
        b = temp;
        }
        printf("%d \n", temp);
    }
    return 0;
}