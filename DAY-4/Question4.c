/* Write a program to Print Armstrong numbers in a range */
#include <stdio.h>
#include <math.h>
int main()
{
    int i, temp, u, l, rem, count = 0, num=0;
    printf("Enter lower limit:\n");
    scanf("%d", &l);
    printf("Enter upper limit:\n");
    scanf("%d", &u);
    printf("The armstrong numbers between %d and %d are:\n", l, u);
    for (i = l; i <= u; i++)
    {   //initializing count and num as 0 for the iteration to be effective
        count=0;
        num=0;
        temp = i;
        while (temp != 0)
        {
            temp = temp / 10;
            count++;
        }
        temp = i;
        while (temp != 0)
        {
            rem = temp % 10;
            num = num + round(pow(rem, count));
            temp /= 10;
        }
        if (i == num)
            printf("%d \n", num);
    }
    return 0;
}