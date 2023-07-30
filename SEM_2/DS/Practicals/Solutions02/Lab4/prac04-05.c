#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};
void init(struct stack *s, int size){
    s->top = -1;
    s->size = size;
    s->arr = (int *)malloc(sizeof(int)*size);
}
void push(struct stack *s, int c){
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
        printf("%d _ ",s->arr[i--]);
    }
}
void change(struct stack *s, int index, int value){
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
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct stack s;
    int n;
    printf("Enter the size of the stack: ");
    scanf("%d",&n);
    init(&s, n);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    return 0;
}