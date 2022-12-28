#include<stdio.h>    
void printFib(int n){    
    static int a=0,b=1,c;    
    if(n>0){    
         c = a + b;
         a = b;    
         b = c;    
         printf("%d ",b);
         printFib(n-1);    
    }    
}    
int main(){
    int n;       
    scanf("%d",&n);    
    printf("Fibonacci Series: ");    
    printf("0 1 ");    
    printFib(n-2);
    return 0;  
 }