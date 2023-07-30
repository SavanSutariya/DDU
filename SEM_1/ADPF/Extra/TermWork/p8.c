#include<stdio.h>
int main(){
    int n=5;
    printf("*");
    for(int i=1; i<=n; i++){
        printf("\n*");
        for(int j=1; j<=i; j++){
            printf("%d",j);
        }
        for(int j=2; j<=i; j++){
            printf("%d",i-j+1);
        }
        printf("*");
    }
    for(int i=2; i<=n; i++){
        printf("\n*");
        for(int j=1; j<=n-i+1; j++){
            printf("%d",j);
        }
        for(int j=2; j<=n-i+1; j++){
            printf("%d",i-j+1);
        }
        printf("*");
    }
    printf("\n*");
}