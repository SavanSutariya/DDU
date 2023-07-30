// Write a program in C to reallocate previously allocated memory space. Print the
// address and value of original array and modified array [Take integer array]

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;

    printf("Enter the size of Array: \n");
    scanf("%d", &n);
    int arr[n];

    int *ptr = (int *) malloc(n * sizeof(int));
    printf("Enter element of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("Original array: \n");
    printf("address of ptr: %d\n", ptr);
    printf("Elements are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    ptr = (int *) realloc(ptr, 2 * n * sizeof(int));
    printf("\nModified Array: \n");
    for (int i = 0; i < n*2; i++)
    {
        printf("%d ", ptr[i]);
    }

    printf("\nadd of ptr: %d \n", ptr);
    free(ptr);
    
    return 0;
}