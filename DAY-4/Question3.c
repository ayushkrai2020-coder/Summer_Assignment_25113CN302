/* Write a program to Check Armstrong number */
#include<stdio.h>
#include<math.h>
int main(){
    int n,num=0,count=0,rem;
    printf("Enter the number:\n");
    scanf("%d",& n);
    int n1=n;
    int n2=n;
    //for finding the number of terms in the number
    while(n1!=0){
        n1=n1/10;
        count++;
    }
    //for finding if the number is armstrong number or not
    while(n2!=0){
        rem=n2%10;
        num=num + round(pow(rem,count));
        n2=n2/10;
    }
    if(n==num){
        printf("The given number is an armstrong number"); 
    }
    else{
        printf("The given number is not an armstrong number");
    }
    return 0;
}