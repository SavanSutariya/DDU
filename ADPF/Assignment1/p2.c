#include<stdio.h>
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    if (m%n){
        printf("0");
    }
    else{
        printf("%d",m/n);
    }
}