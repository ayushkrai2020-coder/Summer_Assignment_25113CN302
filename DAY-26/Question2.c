/* Write a program to Create voting eligibility system */

#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age >= 18) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote. You must be 18 years or older to be able to vote.\n");
        printf("You need to wait %d more year(s) to vote.\n", 18 - age);
    }
    return 0;
}
