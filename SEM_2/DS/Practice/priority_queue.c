#include<stdio.h>
#include<stdlib.h>

#define MAX 20

struct node{
    char val;
    int pri;
    struct node *next;
};

typedef struct{
    struct node *head;
    struct node *tail;
}queue;

void enqueue(queue *,char,int);
// char dequeue(queue *);
// void display(queue *);

void main(){
    queue q1;
    enqueue(&q1, 'A',3);
}
void enqueue(queue *q,char val, int pri){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = val;
    new->pri = pri;
    if(q->head == NULL){
        q->head = new;
        return;
    }
    struct node *tmp = q->head;
    while(tmp->next != NULL && tmp->next->pri > pri){
        tmp = tmp->next;
    }
    printf("\nStopped at %d",tmp->val);
    new->next = tmp->next;
    tmp->next = new;

}