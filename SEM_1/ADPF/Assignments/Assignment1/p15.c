#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int space=1;space<=n-i;space++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("%d ",i);
        }
        printf("\n");
    }
}
// 4
//    1 
//   2 2
//  3 3 3
// 4 4 4 4

