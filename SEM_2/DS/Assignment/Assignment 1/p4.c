// Write a program to sort a stack using recursion (Use of any loop constructs like while, for etc. is not allowed.)
#include <stdio.h>
#include "int_stack.h"
int isEmpty(int_stack *s){return s->top == -1;}
void insertrec(int_stack *s, int item) {
    if (isEmpty(s) || item > peek(s)) {
        push(s, item);
    } else {
        int temp = pop(s);
        insertrec(s, item);
        push(s, temp);
    }
}

void sortStack(int_stack *s) {
    if (!isEmpty(s)) {
        int item = pop(s);
        sortStack(s);
        insertrec(s, item);
    }
}

int main() {
    int_stack s;
    initIntStack(&s);
    push(&s, 1);
    push(&s, 5);
    push(&s, 6);
    push(&s, 3);
    printf("Before sorting:\n");
    display(&s);
    sortStack(&s);
    printf("After sorting:\n");
    display(&s);
    return 0;
}