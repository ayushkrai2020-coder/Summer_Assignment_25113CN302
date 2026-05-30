/* Write a program to Find LCM of two numbers */
#include<stdio.h>

int main(){
    int n1,n2,lcm;
    printf("Enter the two numbers :\n");
    scanf("%d %d",& n1,& n2);
    if(n1>n2){
        for(int i=n1;;i++){
            if(i%n1==0 && i%n2==0){
                lcm=i;
                break;
            }
        }
    }
    else if(n2>n1){
        for(int i=n2;;i++){
            if(i%n1==0 && i%n2==0){
                lcm=i;
                break;
            }
        }
    }
    printf("LCM of the 2 numbers is %d",lcm);
    return 0;
}