#include<stdio.h>
int main(){
    int comp_data[4][4], (*ptr)[4];
    ptr = comp_data;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            scanf("%d",*(ptr+i)+j);
        }
    }
    printf("\n    Q1 Q2 Q3 Q4\n");
    printf("    -- -- -- --\n");
    for (int i = 0; i < 4; i++)
    {
        printf("C%d| ",i+1);
        for(int j = 0; j < 4; j++)
        {
            printf("%d ",*(*(ptr+i)+j));
        }
        printf("\n");   
    }
}
/*
50 55 56 60      
48 53 58 62
20 40 41 31
38 46 54 60
*/