// Write a C program to create a number variable. Create a pointer variable for this number
// variable. Create another pointer-to-pointer variable. Display the address and value of all
// the variables including pointer variables

#include<stdio.h>
int main(){

    int num = 10;
    int *ptr = &num;
    int **p = ptr;

    printf("num: %d --- num(add): %d\n", num, &num);
    printf("ptr: %d --- ptr(add): %d\n", ptr, &ptr);
    printf("p: %d --- p(add): %d\n", p, &p);
    return 0;
}