#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int space=1; space<=n-i; space++){
            printf(" ");
        }
        for(int j=1; j<=i; j++){
            printf("*");
        }
        for(int k=1; k<=i-1; k++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=n-1; i>=1; i--){
        for (int space=1; space<=n-i; space++){
            printf(" ");
        }
        for(int j=i; j>=1; j--){
            printf("*");
        }
        for(int k=i-1; k>=1; k--){
            printf("*");
        }
        printf("\n");
    }
}