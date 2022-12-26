#include<stdio.h>
void fun(){
    char a;
    scanf("%c",&a);
    if(a=='\n')
        return;
    fun();
    printf("%c",a);
}
int main(){
    fun();
    return 0;
}