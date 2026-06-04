/* Write a progrsm to print the repeated number pattern :
 1
 2 2 
 3 3 3 
 4 4 4 4
 5 5 5 5 5 */

 #include<stdio.h>
 
 int main(){
    int n;
    printf("Enter the number of rows of the pattern:\n");
    scanf("%d",& n);
    printf("The repeated number pattern is :\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
 }