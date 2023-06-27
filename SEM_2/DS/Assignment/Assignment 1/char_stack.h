#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int top;
    char *arr;
    int size;
} char_stack;
void initCharStack(char_stack *s, int size){
    s->top = -1;
    s->size = size;
    s->arr = (char *)malloc(sizeof(char) * size);
}
void push(char_stack *s, int item) {
    if (s->top == s->size - 1) {
        printf("Stack Overflow!\n");
        return;
    } else {
        s->arr[++s->top] = item;
    }
}

char pop(char_stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        char item = s->arr[s->top--];
        return item;
    }
}
char peek(char_stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return s->arr[s->top];
    }
}
void display(char_stack *s) {
    int i;
    for (i = 0; i <= s->top; i++) {
        printf("%c", s->arr[i]);
    }
    printf("\n");
}

