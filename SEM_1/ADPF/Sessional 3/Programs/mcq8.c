#include<stdio.h>
int f (int n) 
{ 
 static int i = 1; 
 if (n >= 5) 
 return n; 
 n = n+i; 
 i++; 
 printf("\nn:%d i:%d",n,i);
 return f(n); 
}
int main(){
    printf("%d",f(1));
}