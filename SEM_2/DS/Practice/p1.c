#include <stdio.h>
int add(int a , int b)
{
    return a + b;
}
int sub(int a , int b)
{
    return a - b;
}
int mul(int a , int b)
{
    return a * b;
}
int main()
{
    // array of functions
    int (*ptr1[3])(int, int) = {add, sub, mul};
    printf("%d ", ptr1[0](2, 3));
    // pointer to function
    int (*ptr2)(int, int) = add;
    printf("%d ", (*ptr2)(2, 3));
    printf("%d ", ptr2(2, 3));
    int arr[5] = {1, 2, 3, 4, 5};
    void *ptr = (int *)arr;

    printf("\n%d ", arr);
    printf("%d ", *((int *)(ptr)+1));
    // printf("\n%d ", add);
    // printf("\n%d ", &add);
    // printf("\n%d ", sizeof(add));
    // printf("\n%d ", sizeof(&add));
    // int (*ptr2)(int, int) = add;
    // int *ptr = arr;
    // int *ptr2 = &arr;
    // printf("\n%d ", *ptr2);
    // printf("\n%d ", ptr2);
    // printf("\n%d ", sizeof(*ptr));
    // printf("\n%d ", sizeof(*ptr2));
    // printf("\n%d ", sizeof(arr));
    // printf("\n%d ", sizeof(&arr));
    return 0;
}