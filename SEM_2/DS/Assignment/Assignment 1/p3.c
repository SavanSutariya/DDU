#include <stdio.h>
#include "int_stack.h"
int isEmpty(int_stack *s) {
    return s->top == -1;
}
void insertrec(int_stack *s, int item) {
    if (isEmpty(s)) {
        push(s, item);
    } else {
        int temp = pop(s);
        insertrec(s, item);
        push(s, temp);
    }
}

void reverseStack(int_stack *s) {
    if (!isEmpty(s)) {
        int item = pop(s);
        reverseStack(s);
        insertrec(s, item);
    }
}

int main() {
    int_stack s;
    initIntStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    printf("Before reversal:\n");
    display(&s);
    reverseStack(&s);
    printf("After reversal:\n");
    display(&s);
    return 0;
}
