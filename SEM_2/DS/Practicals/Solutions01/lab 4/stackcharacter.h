#include <stdbool.h>
#include <stdlib.h>

struct stack
{
    int size;
    char *arr;
    int top;
};

void* init(int size)
{
    struct stack *s = malloc(sizeof(struct stack));
    if (s == NULL)
    {
        printf("Memory Error!!");
    }
    else
    {
        s->size = size;
        s->top = -1;
        s->arr = (char *) malloc(size * sizeof(char));
        if (s->arr != NULL)
        {
            return s;
        }
        else
        {
            printf("Memory Error!!");
        }
    }
}

bool isEmpty(struct stack *s)
{
    return s->top == -1;
}

bool isFull(struct stack *s)
{
    return s->top == s->size - 1;
}

void push(struct stack *s, char element)
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

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is Underflow!!\n");
        return '\0';
    }
    else
    {
        return s->arr[s->top--];
    }
}

void display(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is Underflow!!\n");
    }
    else
    {
        printf("\nDisplay all the elements: \n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("|\t%c\t|\n", s->arr[i]);
        }
    }
}

char peak(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is Underflow!!\n");
        return '\0';
    }
    else
    {
        return s->arr[s->top];
    }
}

void change(struct stack *s, int position, char newElement)
{
    if (position > s->top)
    {
        printf("\nPosition is Invalid!!\n");
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