// Int Stack example with static data.

#include <stdio.h>
#include "stackint.h"

int main()
{
    int size;
    printf("Enter the Require size of Stack: \n");
    scanf("%d", &size);

    struct stack *s = init(size);
    // struct stack *s1 = init(5);

    // Push some Element into stack
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    // 2nd stack operation
    // push(s1, 1);
    // push(s1, 2);
    // push(s1, 3);
    // display(s1);
    // printf("Peak Element: %d\n", peak(s1));

    // Display all Element from stack
    display(s);

    // Peck element of stack
    printf("Peak Element: %d\n", peak(s));

    // Pop last element of stack
    pop(s);

    display(s);

    // Change Element from Given postion with new Value
    change(s, 2, 300);

    display(s);

    // check stack is Empty or Not
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack is Not Empty\n");
    }

    // check stack is Full or Not
    if (isFull(s))
    {
        printf("Stack is Full\n");
    }
    else
    {
        printf("Stack is Not Full\n");
    }

    // Display the size of current elements on Stack
    printf("Display Size of Stack : %d", displaySize(s));
    return 0;
}
