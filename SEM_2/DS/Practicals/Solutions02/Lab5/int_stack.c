#include<stdio.h>
#include<stdlib.h>
#define size 100
struct stack{
    int top;
    int *arr;
};
void push(struct stack *s, int c){
    if(s->top < size){
        s->arr[++s->top] = c;
    }
    else{
        printf("Stack Overflow");
    }
}
char pop(struct stack *s){
    if(s->top  > -1){
        return s->arr[s->top--];
    }
    else{
        printf("Stack Underflow");
        return 0;
    }
}