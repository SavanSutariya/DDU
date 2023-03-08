// Write a C program to swap 2 numbers using pass by value and pass by reference to a
// function.

#include<stdio.h>
void passbyvalue(int a , int b){
    int temp = a;
    a = b;
    b = temp;
}

void passbyref(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){

    int a = 10;
    int b = 20;
    passbyvalue(a,b);
    printf("a : %d\n", a);
    printf("b : %d\n", b);
    passbyref(&a,&b);
    printf("a : %d\n", a);
    printf("b : %d\n", b);

    return 0;
}