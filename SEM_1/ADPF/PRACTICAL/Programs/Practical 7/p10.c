#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    while(a%b != 0){
        int tmp = a;
        a = b;
        b = tmp%b;
    }
    printf("===%d",b);
}