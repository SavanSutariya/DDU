// T flip flop
#include<stdio.h>
int Q = 0, Q_comp = 1;
int nand(int a,int b,int c)
{
    return !(a&&b&&c);
}
void T_Flip_Flop(int T,int clc)
{
    int R = nand(Q_comp,T,clc);
    int S = nand(Q,T,clc);

    if (!R)
    {
        Q = nand(R,Q_comp,1);
        Q_comp = nand(S,Q,1);
    }
    else
    {
        Q_comp = nand(S,Q,1);
        Q = nand(R,Q_comp,1);
    }
}
int main(){
    int T = 1,clc=1;
    printf("Enter greater than 1 to exit:");
    while (1){
        printf("\nEnter T and clc: ");
        scanf("%d",&T);
        if (T>1) break;
        scanf("%d",&clc);
        printf("Previous[%d %d]",Q,Q_comp);
        T_Flip_Flop(T,clc);
        printf(" Next[%d %d]",Q,Q_comp);
    }
    return 0;
}