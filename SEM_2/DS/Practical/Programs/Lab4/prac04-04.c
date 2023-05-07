#include<stdio.h>
#include<stdlib.h>
#define size 20
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
    printf("\n");
    while(i>-1){
        printf("%d  ",s->arr[i--]);
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
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->arr = (int *)malloc(size*sizeof(int));
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);

    display(s);
    printf("\npeek : %d ",peek(s));
    printf("\npop : %d ",pop(s));
    printf("\npop : %d ",pop(s));

    display(s);
    change(s, 2, 10);
    display(s);
    return 0;
}