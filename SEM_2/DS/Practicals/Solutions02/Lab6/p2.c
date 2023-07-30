// Write a program to perform all stack operations using singly linked lists. Implement PUSH,
// POP, PEEP, Change and DISPLAY

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct{
    node *top;
} stack;

// function definitions
void display(stack *s) {
    printf("\n");
    if (s->top == NULL) {
        printf("Stack is empty");
        return;
    }
    node *temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }    
}

void push(stack *s, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty");
        return 0;
    }
    node *temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

void peep(stack *s, int i) {
    if (s->top == NULL) {
        printf("Stack is empty");
        return;
    }
    node *temp = s->top;
    for (int j = 1; j < i && temp->next != NULL; j++) {
        temp = temp->next;
    }
    printf("%d", temp->data);
}

void change(stack *s, int i, int data) {
    if (s->top == NULL) {
        printf("Stack is empty");
        return;
    }
    node *temp = s->top;
    for (int j = 1; j < i && temp->next != NULL; j++) {
        temp = temp->next;
    }
    temp->data = data;
}

int main(){
    stack s1;
    s1.top = NULL;
    push(&s1,3);
    printf("\npop=>%d", pop(&s1));
    push(&s1,5);
    push(&s1,11);
    push(&s1,1);
    push(&s1,3);
    display(&s1);
    push(&s1,44);
    display(&s1);
    printf("\npop=>%d", pop(&s1));
    display(&s1);
    peep(&s1, 3);
    change(&s1, 3, 100);
    display(&s1);
}
