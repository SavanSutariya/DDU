#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int lg=0;
    while(n>0){
        int tmp = n%10;
        if (tmp > lg){
            lg = tmp;
        }
        n /= 10;
    }
    printf("%d",lg);
}