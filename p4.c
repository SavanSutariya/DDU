// ending of inputs: -1
// minimum two inputs
// shorted order
//5 6 7 8 -1 : 4 inputs
#include<stdio.h>
int main(){
    int a,b,count=1;
    scanf("%d",&b);
    scanf("%d",&a);
    while(a!=-1){
        if (a!=b){
            count++;
        }
        b=a;
        scanf("%d",&a);
    }
    
    printf("%d",count);
}