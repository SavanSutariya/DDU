#include<stdio.h>
int main(){
    int a,b,mul=0;
    printf("Enter two numbers");
    scanf("%d %d",&a,&b);
    for (int i=1;i<=b;i++){
        mul=mul+a;
    }
    printf("%d",mul);
}