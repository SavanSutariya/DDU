// Write a C program to create a queue where insertion and deletion of elements
// can be done from both the ends
#include <stdio.h>

typedef struct {
    int arr[100];
    int front;
    int rear;
} int_deque;

void initIntDeque(int_deque *d) {
    d->front = -1;
    d->rear = -1;
}

void insertFront(int_deque *d, int item) {
    if (d->front == -1) {
        d->front = 0;
        d->rear = 0;
    } else if (d->front == 0) {
        printf("Deque Overflow!\n");
        return;
    } else {
        d->front--;
    }
    d->arr[d->front] = item;
}

void insertRear(int_deque *d, int item) {
    if (d->front == -1) {
        d->front = 0;
        d->rear = 0;
    } else if (d->rear == 99) {
        printf("Deque Overflow!\n");
        return;
    } else {
        d->rear++;
    }
    d->arr[d->rear] = item;
}

int deleteFront(int_deque *d) {
    if (d->front == -1) {
        printf("Deque Underflow!\n");
        return -1;
    } else {
        int item = d->arr[d->front];
        if (d->front == d->rear) {
            d->front = -1;
            d->rear = -1;
        } else {
            d->front++;
        }
        return item;
    }
}

int deleteRear(int_deque *d) {
    if (d->front == -1) {
        printf("Deque Underflow!\n");
        return -1;
    } else {
        int item = d->arr[d->rear];
        if (d->front == d->rear) {
            d->front = -1;
            d->rear = -1;
        } else {
            d->rear--;
        }
        return item;
    }
}

void display(int_deque *d) {
    int i;
    for (i = d->front; i <= d->rear; i++) {
        printf("%d ", d->arr[i]);
    }
    printf("\n");
}

int main() {
    int_deque d;
    initIntDeque(&d);
    insertFront(&d, 1);
    insertRear(&d, 6);
    insertRear(&d, 7);
    insertRear(&d, 8);
    printf("Delete %d ", deleteFront(&d));
    printf("Delete %d ", deleteFront(&d));
    printf("Delete %d \n", deleteRear(&d));
    display(&d);
    return 0;
}
