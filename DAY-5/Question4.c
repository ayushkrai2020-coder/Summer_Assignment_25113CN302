/* Write a program to Find largest prime factor */
#include<stdio.h>

int main(){
    int n,i,max;
    printf("Enter the number:\n");
    scanf("%d",& n);
    for(i=1;i<=n;i++){
        if(n%i==0){
            int count=0;
            for(int j=1;j<=i;j++){
                if(i%j==0){
                    count++;
                }
            }
            if(count==2){
                    max=i;
                }
        }
    }
    printf("The largest prime factor of %d is %d",n,max);
    return 0;
}