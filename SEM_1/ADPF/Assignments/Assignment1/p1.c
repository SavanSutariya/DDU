// Inputs 3
// Output 1 if different from each other
// output 0 if repeated atleast once
#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d",(a!=b && a!=c && b!=c));
}