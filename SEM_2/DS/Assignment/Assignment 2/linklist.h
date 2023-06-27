#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;
void insert(node **head, int val){
    // Link list: Inserts a new node at the end
    node *new = (node *)malloc(sizeof(node));
    new->val=val;
    new->next=NULL;
    if(*head == NULL){
        *head = new;
        return;
    }
    node *tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = new;
}
void display(node *head){
    // Link list: Display
    printf("\n");
    if(head == NULL){
        printf("(Empty)");
        return;
    }
    while(head != NULL){
        printf("%d | ",head->val);
        head = head->next;
    }
}
void insertOrdered(node **head, int val){
    //inserts in sorted order
    node *new = (node *)malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    if(*head == NULL){
        *head = new;
        return;
    }
    node *tmp = *head;
    if(tmp->val>val){
        new->next = *head;
        *head= new;
        return;
    }
    while(tmp->next != NULL){
        if(tmp->next->val>val){
            new->next = tmp->next;
            tmp->next = new;
            return;
        }
        tmp = tmp->next;
    }
    tmp->next = new;
}
