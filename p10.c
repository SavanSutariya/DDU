#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int space=1;space<=n-i;space++){
            printf(" ");
        }
        for(int j=i;j<(i*2);j++){
            printf("%d",j);
        }
        for(int k=(i*2-2);k>=i;k--){
            printf("%d",k);
        }
        printf("\n");
    }
}