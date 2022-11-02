#include <stdio.h>
int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    for(int i=1;i<=10;i++){
        printf("%d  x %2d = %4d\n",n,i,n*i);
    }
}