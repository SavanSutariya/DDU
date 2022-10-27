// ending of inputs: -1
// minimum two inputs
// shorted order
//5 6 7 8 -1 : 4 inputs
#include<stdio.h>
int main(){
    int a,b;
    scanf("%d",&b);
    scanf("%d",&a);
    while(a!=-1){
        if (a!=b){
            printf("1");
            return 0;
        }
        b=a;
        scanf("%d",&a);
    }
    printf("0");
}