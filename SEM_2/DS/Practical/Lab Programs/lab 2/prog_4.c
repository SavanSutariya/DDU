// Create a function in C to accept an integer and function pointer as argument. Write a C program
// with two functions, one which increments the int argument by 2 and the other which decrements
// the int argument by 2. Demonstrate the use of passing pointer to function argument using these
// three functions. User will enter an integer number and select if he wants to add or subtract the
// number

#include<stdio.h>

int fun1(int num)
{
    return num + 2;
}
int fun2(int num2)
{
    return num2 - 2;
}
void funptr(int no, int (*ptr)(int)){
    printf("old: %d -- new: %d", no, ptr(no));
}
int main()
{
    char choice;
    int num;

    printf("Enter Choice: 1+   2-:\n");
    scanf("%d", &num);
    scanf("%d", &choice);
   
    if(choice == '+'){
        funptr(num, fun1);
    }else{
        funptr(num, fun2);
    }
    return 0;
}