// Write a C program to accept a number n from the user and create an array of size n
// using dynamic memory allocation. Accept and store values in the array. Now take
// another number m from the user and revise the array size using dynamic memory
// allocation. Accept and store values in the revised array. Find the sum of all elements in
// both cases.

#include<stdio.h>
#include<stdlib.h>

int main(){

    int *p, *p1,n,m;
    int sum1 = 0, sum2 = 0;

    printf("Enter n:\n");
    scanf("%d", &n);
    p = (int *) malloc(n * sizeof(int));
    if(p == NULL){
        printf("memory is not free!");
        exit(0);
    }
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
        sum1 += p[i];
    }

    printf("Enter m: \n");
    scanf("%d", &m);
    p1 = (int *) realloc(p, m * sizeof(int));

    printf("Enter elements for m: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &p1[i]);
        sum2 += p1[i];
    }

    printf("sum of elems in original array: %d \n", sum1);
    printf("sum of elems in revised array: %d \n", sum2);
    printf("Add of p : %d\n", p);
    printf("Add of p1 : %d\n", p1);

    free(p);
    free(p1);
    return 0;
}