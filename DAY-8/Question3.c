/* Write a program to print the character triangle :
 A
 A B 
 A B C 
 A B C D
 A B C D E */

 #include<stdio.h>
 
 int main(){
    int n;
    char ch;
    printf("Enter the number of rows of the pattern:\n");
    scanf("%d",& n);
    printf("The character triangle pattern is :\n");
    for(int i=1;i<=n;i++){
        ch='A';
        for(int j=1;j<=i;j++){
            printf("%c ",ch);
            ch++;
        }
        printf("\n");
    }
    return 0;
 }