#include<stdio.h>

int main(){

    int x,y;
    printf("\nEnter X and Y : ");
    scanf("%d %d",&x,&y);

    printf("\nBefore Swap X: %d & Y: %d",x,y);

    x=x ^ y;
    y=x ^ y;
    x=x ^ y;

    printf("\nAfter Swap X: %d & Y: %d",x,y);

    return 0;
}