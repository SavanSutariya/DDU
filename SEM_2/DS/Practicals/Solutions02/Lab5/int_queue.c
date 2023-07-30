#define MAX 100
struct int_queue
{
    int data[MAX];
    int front;
    int rear;
};

void enqueue(struct int_queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue is full");
        return;
    }
    if (q->front == -1)
    {
        q->front++;
    }
    q->data[++q->rear] = value;
}

int dequeue(struct int_queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty");
        return 0;
    }
    if (q->front == q->rear)
    {
        // last element
        int value = q->data[q->front];
        q->rear = q->front = -1;
        return value;
    }
    else
    {
        // printf("Returned %d",q->data[q->front+1]);
        return q->data[q->front++];
    }
}
void display(struct int_queue *q)
{
    printf("\n Queue:");
    if (q->front == -1)
    {
        printf("Queue is empty");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf(" %d ", q->data[i]);
    }
}
