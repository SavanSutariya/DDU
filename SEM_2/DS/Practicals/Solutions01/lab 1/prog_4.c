// Write a C program to create an array of 15 elements. create a pointer which points to an
// array. Now print the base address of the array. Then display the array elements using
// pointer arithmetic.

#include<stdio.h>
#define SIZE 5
int main(){

    // int n = 5;
    int arr[SIZE] = {10,20,30,40,50};
    int *ptr = arr;

    printf("base add: %d \n", arr);
    for (int i = 0; i < SIZE; i++)
    {
        // printf("%d ", *(ptr+i));
        printf("%d ", ptr[i]);

    }
    
    return 0;
}