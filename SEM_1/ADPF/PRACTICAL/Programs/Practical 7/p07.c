#include<stdio.h>
int main(){
    int a=0,b=1,n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int tmp = a;
        a = b;
        b= tmp+a;
        printf("%d  ",b);
    }
    return 0;
}