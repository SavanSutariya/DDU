#include <stdio.h>
#include "int_queue.c"

void reverse(struct int_queue *q)
{
    int temp[MAX];
    int i = 0;
    while (q->front != -1)
    {
        temp[i] = dequeue(q);
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        enqueue(q, temp[j]);
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