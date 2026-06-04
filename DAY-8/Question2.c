/* Write a program to print the numbeer triangle :
  1
  1 2 
  1 2 3 
  1 2 3 4
  1 2 3 4 5 */

  #include<stdio.h>
  
  int main(){
    int n;
    printf("Enter the number of rows of the pattern:\n");
    scanf("%d",& n);
    printf("The number triangle pattern is :\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
  }