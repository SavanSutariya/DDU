#include<stdio.h>
#include<stdlib.h>
#define size 20
struct stack{
    int top;
    char *arr;
};

void push(struct stack *s, char c){
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
    if(s->top >= size){
        return 1;
    }
    else{
        return 0;
    }
}
int is_empty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    struct stack s1;
    s1.arr = (char *)calloc(sizeof(char),size);
    s1.top = -1;
    push(&s1,'D');
    push(&s1,'D');
    push(&s1,'U');
    push(&s1,'U');
    printf("\n1 : %s",s1.arr);
    printf("\n'%c' popped",pop(&s1));
    printf("\n %c is the element on top", peek(&s1));
    printf("\n");
    change(&s1,2,'S');
    display(&s1);
    printf("IS full %d",is_full(&s1));
    printf("IS Empty %d",is_empty(&s1));
    return 0;
}