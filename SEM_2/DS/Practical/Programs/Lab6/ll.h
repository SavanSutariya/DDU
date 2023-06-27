// header file for linked list C 

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct{
    node *head;
} linkedList;

// function definitions
void display(linkedList *list) {
    printf("\n");
    if (list->head == NULL) {
        printf("List is empty");
        return;
    }
    node *temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }    
}

void insertAtFirst(linkedList *list, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtLast(linkedList *list, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    node *temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(linkedList *list, int data, int position) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (position == 1) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    node *temp = list->head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtFirst(linkedList *list) {
    if (list->head == NULL) {
        printf("List is empty");
        return;
    }
    node *temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void deleteAtLast(linkedList *list) {
    if (list->head == NULL) {
        printf("List is empty");
        return;
    }
    node *temp = list->head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(linkedList *list, int position) {
    if (list->head == NULL) {
        printf("List is empty");
        return;
    }
    if (position == 1) {
        node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }
    node *temp = list->head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}

void deleteElement(linkedList *list, int data) {
    if (list->head == NULL) {
        printf("List is empty");
        return;
    }
    if (list->head->data == data) {
        node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }
    node *temp = list->head;
    while (temp->next->data != data) {
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}

void sortList(linkedList *list) {
    if (list->head == NULL) {
        printf("List is empty");
        return;
    }
    node *temp = list->head;
    while (temp != NULL) {
        node *temp2 = temp->next;
        while (temp2 != NULL) {
            if (temp->data > temp2->data) {
                int tempData = temp->data;
                temp->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}