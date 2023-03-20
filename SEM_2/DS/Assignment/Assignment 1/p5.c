#include <stdio.h>
#include "int_stack.h"

typedef struct {
    int_stack s1;
    int_stack s2;
} int_queue;

void initIntQueue(int_queue *q) {
    initIntStack(&q->s1);
    initIntStack(&q->s2);
}
int isEmpty(int_stack *s) {return s->top == -1;}
void enqueue(int_queue *q, int item) {
    push(&q->s1, item);
}

int dequeue(int_queue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

int main() {
    int_queue q;
    initIntQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    return 0;
}
