#define MAX 100 // maximum size of stack

struct char_stack {
    int top;
    char arr[MAX];
};
int is_full(struct char_stack *s) {
    return s->top == MAX - 1;
}

int is_empty(struct char_stack *s) {
    return s->top == -1;
}
void push(struct char_stack *s, char item) {
    if (is_full(s)) {
        printf("Stack Overflow!");
        return;
    }
    s->top++;
    s->arr[s->top] = item;
}

char pop(struct char_stack *s) {
    if (is_empty(s)) {
        printf("Stack Underflow!");
        return '\0';
    }

    char item = s->arr[s->top];
    s->top--;
    return item;
}

char peep(struct char_stack *s, int i) {
    if (is_empty(s)) {
        printf("Stack Underflow!");
        return '\0';
    }

    return s->arr[s->top-i+1];
}

void display(struct char_stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%c ", s->arr[i]);
    }
    printf("\n");
}

void change(struct char_stack *s, int index, char item) {
    if (index < 0 || index > s->top) {
        printf("Index out of range!");
        return;
    }

    s->arr[index] = item;
}