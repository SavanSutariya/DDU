#include <stdio.h>
#include "int_queue.c"
#include "int_stack.c"

void reverse(struct int_queue *q)
{
    struct stack s;
    s.top = -1;
    s.arr = (int *)malloc(sizeof(int) * MAX);
    while (q->front != -1)
    {
        push(&s, dequeue(q));
    }
    while (s.top != -1)
    {
        enqueue(q, pop(&s));
    }
}

int main()
{
    struct int_queue q1;
    q1.front = -1;
    q1.rear = -1;
    enqueue(&q1, 4);
    enqueue(&q1, 3);
    enqueue(&q1, 7);
    enqueue(&q1, 2);
    enqueue(&q1, 5);
    enqueue(&q1, 9);
    display(&q1);
    reverse(&q1);
    display(&q1);
}
// output:
// Queue: 4 3 7 2 5 9
// Queue: 9 5 2 7 3 4