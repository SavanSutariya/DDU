#include <stdio.h>
#include <stdlib.h>

#define MAX 10

char stack[MAX];
int top = -1;

// Function to check if the stack is full
int is_full() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
int is_empty() {
    return top == -1;
}

// Function to add an item to the stack
void push(char item) {
    if (!is_full()) {
        stack[++top] = item;
        printf("Item %c has been added to the stack\n", item);
    } else {
        printf("Error: Stack is full\n");
    }
}

// Function to remove an item from the stack
char pop() {
    if (!is_empty()) {
        return stack[top--];
    } else {
        printf("Error: Stack is empty\n");
        return '\0';
    }
}

// Function to peek at the top item in the stack
char peek() {
    if (!is_empty()) {
        return stack[top];
    } else {
        printf("Error: Stack is empty\n");
        return '\0';
    }
}

// Function to change the value of an item in the stack
void change(char item, int position) {
    if (position <= top) {
        stack[position - 1] = item;
        printf("Item %c has been changed to %c\n", stack[position - 1], item);
    } else {
        printf("Error: Invalid position\n");
    }
}

// Function to display the items in the stack
void display() {
    int i;
    printf("Stack: ");
    for (i = top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    char item;
    int pos;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Change\n");
        printf("6. Check if full\n");
        printf("7. Check if empty\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf(" %c", &item);
                push(item);
                break;
            case 2:
                item = pop();
                printf("Item %c has been removed from the stack\n", item);
                break;
            case 3:
                item = peek();
                printf("Top item: %c\n", item);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter the item: ");
                scanf(" %c", &item);
                printf("Enter the position: ");
                scanf("%lc", &pos);
                change(pos, item);
                break;
            case 6:
                if (is_empty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 7:
                if (is_full())
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Nothing\n");
                break;
            }
        }
    }