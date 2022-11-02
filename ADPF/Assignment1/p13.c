#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for (int i=n; i>=1; i--){
        if(i==n){
            printf("*"); //There may be a printing error in the pdf (prints same as pdf)
        }
        for(int j=1; j<=i; j++){
            if(i==1 || j==1 || i==n || j==i){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
/*

******
*  *
* *
**
*

*/