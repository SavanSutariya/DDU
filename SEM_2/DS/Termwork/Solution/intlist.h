#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;
typedef struct linklist{
    node *head;
}linklist;

node *createNode(int val){
    node *new = (node *)malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    return new;
}

void insert(linklist *l,int val){
    node *new = createNode(val);
    if(l->head == NULL){
        l->head = new;
        return;
    }
    node *tmp = l->head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = new;
}

void display(linklist *l){
    printf("\n");
    if(l->head == NULL){
        printf("Empty");
        return;
    }
    node *tmp = l->head;
    while(tmp != NULL){
        printf("%d ",tmp->val);
        tmp = tmp->next;
    }
}
