#include <stdio.h>
#include "int_queue.c"
int main()
{
    struct int_queue q1;
    q1.front = -1;
    q1.rear = -1;
    enqueue(&q1, 4);
    enqueue(&q1, 3);
    display(&q1);
    printf("\n Dequeued %d", dequeue(&q1));
    enqueue(&q1, 7);
    enqueue(&q1, 2);
    enqueue(&q1, 5);
    enqueue(&q1, 9);
    display(&q1);
    printf("\n Dequeued %d", dequeue(&q1));
    enqueue(&q1, 3);
    enqueue(&q1, 9);
    display(&q1);
    return 0;
}


// output:
// Queue: 4 3
// Dequeued 4
// Queue: 3 7 2 5 9
// Dequeued 3
// Queue: 7 2 5 9 3 9
