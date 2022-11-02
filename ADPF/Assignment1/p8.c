#include <stdio.h>
int main(){
    int a,ln;
    scanf("%d",&a);
    ln = a%10;
    while(a>10){
        a=a/10;
    }
    printf("Sum_of_First_and_Last_digit_%d",a+ln);
}