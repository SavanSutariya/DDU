#include "person_queue.c"


int main()
{
    struct person_queue q1;
    q1.front = -1;
    q1.rear = -1;
    struct person p1;
    p1.name = 'A';
    p1.amt = 500;
    enqueue(&q1, p1);
    p1.name = 'B';
    p1.amt = 1000;
    enqueue(&q1, p1);
    display(&q1);
    p1 = dequeue(&q1);
    printf("\n Dequeued %c", p1.name);
    p1.name = 'C';
    p1.amt = 1500;
    enqueue(&q1, p1);
    p1.name = 'D';
    p1.amt = 2000;
    enqueue(&q1, p1);
    p1.name = 'E';
    p1.amt = 2200;
    enqueue(&q1, p1);
    p1.name = 'F';
    p1.amt = 2500;
    enqueue(&q1, p1);
    display(&q1);
    p1 = dequeue(&q1);
    printf("\n Dequeued %c", p1.name);
    p1.name = 'C';
    p1.amt = 5000;
    enqueue(&q1, p1);
    p1.name = 'D';
    p1.amt = 5500;
    enqueue(&q1, p1);
    display(&q1);
    return 0;
}