#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++)
            printf("*");
        for(int space=1; space<=i-1; space++)
            printf("  ");
        for(int j=1; j<=n-i+1; j++)
            printf("*");
        printf("\n");
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            printf("*");
        for(int space=1; space<=n-i; space++)
            printf("  ");
        for(int j=1; j<=i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}