// Write a C program to create a function to accept a number and check whether it is even or odd.
// Call the function using function pointer


#include <stdio.h>
int odd_even(int num)
{
    if (num % 2 == 0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int (*ptr)(int)= &odd_even;
    printf( "%d", ptr(6));
    return 0;
}