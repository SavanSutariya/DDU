#include <stdio.h>
int main(){
    int a,fact=1;
    scanf("%d",&a);
    for (int i = 1; i <=a; i++)
    {
        fact=fact*i;
    }
    printf("The_factorial_of_%d_is_%d",a,fact);
}