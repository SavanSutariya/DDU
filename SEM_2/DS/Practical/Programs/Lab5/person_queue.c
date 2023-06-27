#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct person
{
    char name;
    int amt;
};

struct person_queue
{
    int front;
    int rear;
    struct person data[MAX];
};

void enqueue(struct person_queue *q, struct person value)
{
    if ((q->rear + 1) % MAX == q->front)
    { // Queue is full
        printf("\nQueue is full");
        return;
    }
    if (q->front == -1 && q->rear == -1)
    { // First element
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX; // Circular increment
    }
    q->data[q->rear] = value;
}

struct person dequeue(struct person_queue *q)
{
    if (q->front == -1)
    { // Queue is empty
        printf("\nQueue is empty");
        struct person p;
        p.name = ' ';
        p.amt = 0;
        return p;
    }
    struct person value = q->data[q->front];
    if (q->front == q->rear)
    { // Last element
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX; // Circular increment
    }
    return value;
}

void display(struct person_queue *q)
{
    if (q->front == -1)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue contains:");
    int i = q->front;
    while (i != q->rear)
    {
        printf(" %c", q->data[i].name);
        i = (i + 1) % MAX; // Circular increment
    }
    printf(" %c", q->data[q->rear].name);
}