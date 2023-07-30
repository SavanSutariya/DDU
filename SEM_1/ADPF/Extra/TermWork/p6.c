#include<stdio.h>
int main(){
    int N,lwr=0,upr=0;
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int a;
            scanf("%d",&a);
            if(j<i)
                lwr+=a;
            else if(j>i)
                upr+=a;
        }
    }
    if(lwr==0 || upr==0)
        printf("yes");
    else
        printf("no");
    return 0;
}