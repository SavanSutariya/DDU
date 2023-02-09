#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

int is_empty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

int is_full() {
    if (top == MAX-1)
        return 1;
    else
        return 0;
}

void push(int item) {
    if (is_full())
        printf("Stack Overflow\n");
    else
        stack[++top] = item;
}

int pop() {
    if (is_empty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    else
        return stack[top--];
}

int peep() {
    if (is_empty()) {
        printf("Stack is empty\n");
        return -1;
    }
    else
        return stack[top];
}

void display() {
    int i;
    if (is_empty())
        printf("Stack is empty\n");
    else {
        for (i=top; i>=0; i--)
            printf("%d\n", stack[i]);
    }
}

void change(int pos, int item) {
    if (is_empty())
        printf("Stack is empty\n");
    else if (pos > top)
        printf("Invalid position\n");
    else
        stack[pos] = item;
}

int main() {
    int choice, item, pos;
    while (1) {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. DISPLAY\n");
        printf("5. CHANGE\n");
        printf("6. IS_EMPTY\n");
        printf("7. IS_FULL\n");
        printf("8. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1)
                    printf("Popped item: %d\n", item);
                break;
            case 3:
                item = peep();
                if (item != -1)
                    printf("Top item: %d\n", item);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter the position to be changed: ");
                scanf("%d", &pos);
                printf("Enter the new item: ");
                scanf("%d", &item);
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

