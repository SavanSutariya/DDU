#define MAX_SIZE 100

struct int_stack {
    int top;
    int arr[MAX_SIZE];
};

void push(struct int_stack *s, int item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
    } else {
        s->arr[++s->top] = item;
    }
}

int pop(struct int_stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int item = s->arr[s->top--];
        return item;
    }
}

