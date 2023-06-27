#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    char *arr;
};
void init(struct stack *s, int size){
    s->top = -1;
    s->size = size;
    s->arr = (char *)malloc(s->size*sizeof(char));
}
void push(struct stack *s, char c){
    if(s->top < s->size){
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
char peek(struct stack *s){
    if(s->top == -1){
        printf("Stack is empty");
        return 0;
    }
    else{
        return s->arr[s->top];
    }
}
void display(struct stack *s){
    int i = s->top;
    while(i>-1){
        printf("%c _ ",s->arr[i--]);
    }
}
void change(struct stack *s, int index, char value){
    if(index <= s->top && index > -1){
        s->arr[index] = value;
    }
    else{
        printf("Invalid index");
    }
}
int is_full(struct stack *s){
    if(s->top >= s->size){
        return 1;
    }
    else{
        return 0;
    }
}
int is_empty(struct stack *s){
    return (s->top == -1);
}