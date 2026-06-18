/* Write a program to Reverse a string */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    strrev(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
