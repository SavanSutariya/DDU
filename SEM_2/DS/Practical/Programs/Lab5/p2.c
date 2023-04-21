#include <stdio.h>
#define MAX 5

struct int_queue{
    int data[MAX];
    int front;
    int rear;
    int size;
};

void enqueue(struct int_queue *q, int value){
    if ((q->rear + 1) % MAX == q->front){ // Queue is full
        printf("\nQueue is full");
        return;
    }
    if (q->front == -1 && q->rear == -1){ // First element
        q->front = q->rear = 0;
    }
    else{
        q->rear = (q->rear + 1) % MAX; // Circular increment
    }
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(struct int_queue *q){
    if (q->front == -1){ // Queue is empty
        printf("\nQueue is empty");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear){ // Last element
        q->front = q->rear = -1;
    }
    else{
        q->front = (q->front + 1) % MAX; // Circular increment
    }
    q->size--;
    return value;
}

void display(struct int_queue *q){
    if (q->front == -1){
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue contains:");
    int i = q->front;
    while(i != q->rear){
        printf(" %d",q->data[i]);
        i = (i + 1) % MAX; // Circular increment
    }
    printf(" %d",q->data[q->rear]);
}

int main(){
    struct int_queue q1;
    q1.front = -1;
    q1.rear = -1;
    q1.size = 0;

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    display(&q1);
    dequeue(&q1);
    enqueue(&q1, 4);
    enqueue(&q1, 5);
    printf("\nfront: %d, rear: %d", q1.front, q1.rear);
    display(&q1);
    enqueue(&q1, 6);
    printf("\nfront: %d, rear: %d", q1.front, q1.rear);
    display(&q1);
    return 0;
}

// output:
// Queue contains: 1 2 3
// front: 1, rear: 4
// Queue contains: 2 3 4 5
// front: 1, rear: 0
// Queue contains: 2 3 4 5 6