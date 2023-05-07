#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct{
    int queue[MAX];
    int front;
    int rear;
}queue;
void enqueue(queue *,int);
int dequeue(queue *);
void display(queue *);
int main(){
    queue q1;
    q1.front = -1;
    q1.rear=-1;
    enqueue(&q1,5);
    enqueue(&q1,6);
    enqueue(&q1,2);
    printf("\nDe(%d)",dequeue(&q1));
    printf("\nDe(%d)",dequeue(&q1));
    printf("\nDe(%d)",dequeue(&q1));
    display(&q1);
    enqueue(&q1,6);
    display(&q1);

}

void enqueue(queue *q,int val){
    if(q->front == -1){
        q->front++;
        q->queue[++q->rear] = val;
        return;
    }
    if(q->rear == MAX-1){
        printf("\nQueue is full");
        return;
    }
    q->queue[++q->rear] = val;
}

int dequeue(queue *q){
    if(q->front == -1){
        printf("\nQueue is empty");
        return 0;
    }
    if(q->front == q->rear){
        int val = q->queue[q->front];
        q->front = q->rear = -1;
        return val;
    }
    return q->queue[q->front++];
}

void display(queue *q){
    if(q->front == -1){
        printf("\nQueue is empty");
        return;
    }
    printf("\n");
    for(int i=q->front;i<=q->rear;i++){
        printf("|%d| ",q->queue[i]);
    }
}