#include<stdio.h>
void fun(){
    char a;
    scanf("%c",&a);
    if(a=='\n') // CTRL+Z -> 26
        return;
    fun();
    printf("%c",a);
}
int main(){
    fun();
    return 0;
}





// #include<stdio.h>
// void fun(){
//     char a;
//     scanf("%c",&a);
//     if(a==EOF)
//         return;
//     fun();
//     printf("%i ",a);
// }
// int main(){
//     fun();
//     return 0;
// }