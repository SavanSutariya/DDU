// Simple character stack Implementation.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 10

int top = -1;
char stack[size];

bool isEmpty()
{
    if(top == -1){
        return true;
    }
    return false;
}

bool isFull()
{
    if(top == size - 1){
        return true;
    }
    return false;
}

void push(char ele)
{
    if (isFull())
    {
        printf("Stack is Overflow!!push\n");
    }else
    {
        top++;
        stack[top] = ele;
    }
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack is Underflow!!\n");
    }else
    {
        return stack[top--];
    }
}

char peak()
{
    if (isEmpty())
    {
        printf("Stack is Underflow!!\n");
    }else
    {
        return stack[top];
    }
}

void change(int position, char element)
{
    if(isFull()){
        printf("Stack is Overflow!!");
    }else if(position > top){
        printf("Invalid Position!!");
    }else{
        stack[position - 1] = element;
    }

}

void display()
{
    if(isEmpty()){
        printf("Stack is Underflow!!");
    }else{
        for(int i = top; i >= 0; i--){
            printf("%c\n", stack[i]);
        }
    }
}
int main()
{
    int choice , postion;
    char element;

    while(1){
        printf("\n1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Peak element\n");
        printf("4. Display element\n");
        printf("5. Change element\n");
        printf("6. isEmpty element\n");
        printf("7. isFull element\n");
        printf("8. Exit element\n");
        printf("Enter your Choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                    printf("Enter push element into stack: \n");
                    scanf("%s", &element);
                    push(element);
                    break;
            case 2:
                    printf("Pop element from stack: %d", pop());
                    break;
            case 3:
                    printf("Peak element into stack: %d", peak());
                    break;

            case 4:
                    printf("Display elements From stack: \n");
                    display();
                    break;
                    
            case 5:
                    printf("Enter the position to be changed: \n");
                    scanf("%d", &postion);
                    printf("Enter element: ");
                    scanf("%d", &element);
                    change(postion, element);
                    break;

            case 6:
                    if(isEmpty){
                        printf("Stack is Empty!!\n");
                    }else{
                        printf("Stack is not Empty\n");
                    }
                    break;

            case 7:
                    if(isFull){
                        printf("Stack is Full!!\n");
                    }else{
                        printf("Stack is not full\n");
                    }
                    break;

            case 8:
                    exit(0);
                    break;
        
        default:
            printf("plz Enter valid choice");
            break;
        }
    }

    return 0;
}