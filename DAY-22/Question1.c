/* Write a program to Check palindrome string */

#include <stdio.h>
#include <string.h>

int main()
{
    char original[100], reversed[100];
    printf("Enter a string: ");
    scanf("%99s", original);
    strcpy(reversed, original);
    strrev(reversed);
    if (strcmp(original, reversed) == 0)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
