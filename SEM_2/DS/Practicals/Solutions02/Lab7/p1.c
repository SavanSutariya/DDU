#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;  
    struct node *next;
};
typedef struct{
    struct node *head;
    struct node *tail;
} queue;

void enqueue(queue *q, int value){
    if(q->tail == NULL && q->head == NULL){
        q->head = (struct node *)malloc(sizeof(struct node));
        q->head->value = value;
        q->head->next = q->head;
        q->tail = q->head;
        return;
    }
    struct node *tmp = q->head;
    while(tmp != q->tail){
        tmp=tmp->next;
    }
    tmp->next = (struct node *)malloc(sizeof(struct node));
    tmp->next->value=value;
    tmp->next->next = q->head;
    q->tail = tmp->next;
}
int dequeue(queue *q){
    if(q->head == NULL || q->tail == NULL){
        printf("empty queue");
        return 0;
    }
    if(q->head == q->tail){
        int val = q->head->value;
        free(q->head);
        q->head = NULL;
        q->tail = NULL;
        return val;
    }
    struct node *tmp = q->head;
    int val = tmp->value;
    q->head = q->head->next;
    q->tail->next = q->head;
    free(tmp);
    return val;
}
void display(queue *q){
    if(q->head == NULL && q->tail == NULL){
        printf("Queue empty!!");
        return;
    }
    struct node *tmp = q->head;
    printf("\n");
    while(tmp != q->tail){
        printf("(%p)|%d|%p| - ",tmp,tmp->value,tmp->next);
        tmp=tmp->next;
    }
    printf("(%p)|%d|%p| - ",tmp,tmp->value,tmp->next);
}

int main(){
    queue q;
    q.head = NULL;
    q.tail = NULL;
    // printf("%d %d",q.head->value,q.head->next->value);
    enqueue(&q,5);
    enqueue(&q,6);
    enqueue(&q,9);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,94);
    display(&q);
    return 0;
}