// Write a program to create a value array and another pointer array. Both array sizes should
// be 5. Now store some values in the value array. Then store the address of these five
// elements in the pointer array. Then print the address and value of each of the pointer
// arrays.

#include<stdio.h>

int main(){

    int arr[5] = {1,2,3,4,5};
    int *ptr[5];

    for (int i = 0; i < 5; i++)
    {
        ptr[i] = &arr[i];

        printf("ptr[%d] -- arr[%d] -- ptr[%d](add) -- arr[%d](add) \n", ptr[i], arr[i],&ptr[i], &arr[i]);
    }
    
    return 0;
}