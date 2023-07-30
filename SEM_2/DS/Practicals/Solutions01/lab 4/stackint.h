#include <stdbool.h>
#include <stdlib.h>
struct stack
{
    int size;
    int *arr;
    int top;
};

void* init(int size){
    struct stack *s = malloc(size*sizeof(struct stack));
    if(s == NULL){
        printf("Memory Error!!");
    }else{
        s->size = size;
        s->top = -1;
        s->arr = (int *) malloc(size * sizeof(int));
        if(s->arr != NULL){
            return s;
        }else{
            printf("Memory Error!!");
        }   
    }
}

// Return bool if Stack is Empty or not
bool isEmpty(struct stack *s)
{
    return s->top == -1;
}

// Return bool if Stack is Full or not
bool isFull(struct stack *s)
{
    return s->top == s->size - 1;
}

// Push Element on Stack if Stack is Not full
void push(struct stack *s, int element)
{
    if (isFull(s))
    {
        printf("\nStack is Overflow!!\n");
    }
    else
    {
        s->arr[++s->top] = element;
    }
}

// Return Pop Element if Stack is Not Empty
int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is Underflow!!\n");
    }
    else
    {
        return s->arr[s->top--];
    }
}
// Diplay all the Elments
void display(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is Underflow!!\n");
    }
    else
    {
        printf("\nDisplay all the  elements: \n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("|\t%d\t|\n", s->arr[i]);
        }
    }
}

// Return the peak element of Stack if Stack is not Empty
int peak(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is Underflow!!\n");
    }
    else
    {
        return s->arr[s->top];
    }
}

// Change any Element on Stack just Passing postion and new Elements
void change(struct stack *s, int position, int newElement)
{
    if (position > s->top)
    {
        printf("\nPostion is Invalid!!\n");
    }
    else
    {
        s->arr[position] = newElement;
    }
}

int displaySize(struct stack *s)
{
    int count = 0;
    for (int i = s->top; i >= 0; i--)
    {
        count++;
    }
    return count;
}