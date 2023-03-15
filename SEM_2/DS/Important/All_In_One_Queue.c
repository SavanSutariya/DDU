#include <string.h>
/* OVERFLOW */
int IS_OVERFLOW(int front, int rear, int Size, char *Q_Type)
{
    if ((strcmp(Q_Type, "NORMAL") == 0))
    {
        if (rear == Size - 1)
        {
            printf("\nOverflow....");
            return 1;
        }
    }
    else
    {
        if ((front == rear + 1) || (front == 0 && rear == Size - 1))
        {
            printf("\nOverflow....");
            return 1;
        }
    }
    return 0;
}
int IS_UNDERFLOW(int front)
{
    if (front == -1)
    {
        /* code */
        printf("\nUnderflow..");
        return 1;
    }
    return 0;
}
/*EnQueue*/
int Enqueue(int Queue[], int Q_Size, int *front, int *rear, int item, char *Q_Type)
{
    if (!IS_OVERFLOW(*front, *rear, Q_Size, Q_Type))
    {
        // NORMAL QUEUE
        if (strcmp(Q_Type, "NORMAL") == 0)
        {
            /* HANDLING FIRST ELEMENT */

            if (*front == -1)
                *front = 0;
            Queue[++(*rear)] = item;
            printf("\n%d Is EnQueued..", Queue[*rear]);
            return 1;
        }
        /* CIRCULAR QUEUE */
        else
        {
            /* FIRST ELEMENT*/
            if (*front == -1)
                *front = 0;
            /* LAST ELEMENT BUT Queue Having Space */
            else if (*rear == Q_Size - 1 && *front != 0)
                *rear = -1; // Leter Incerement
            Queue[++(*rear)] = item;
            printf("\n%d Is EnQueued..", Queue[*rear]);
            return 1;
        }
    }

    return 0;
}

// DeQueue
int DeQueue(int Queue[], int Size, int *front, int *rear, char *Q_Type)
{
    if (!IS_UNDERFLOW(*front))
    {
        /* code */
        int temp = *front;

        // NORMAL
        if (!strcmp(Q_Type, "NORMAL"))
        {
            if (*front == *rear || *front == Size - 1)
            {
                *front = *rear = -1;
            }
            else
            {
                (*front)++;
            }
            printf("\n%d is Deleted...", Queue[(temp)]);
            return Queue[temp];
        }
        // CIRCULAR
        else
        {
            if (*front == *rear)
            {
                *front = *rear = -1;
            }
            else if (*front == Size - 1)
            {
                *front = 0;
            }
            else
            {
                (*front)++;
            }
            printf("\n%d is Deleted...", Queue[(temp)]);
            return Queue[temp];
        }
    }
    return 0;
}

/* DOBULE ENDED QUEUE AND OTHER OPERATION*/

int INSERT_FIRST(int Queue[], int Q_Size, int *front, int *rear, int item, char *Q_Type)
{
    // NORMAL QUEUE
    if (strcmp(Q_Type, "NORMAL") == 0)
    {
        if (*front == 0)
        {
            printf("\nOperation Can not Perform...!!");
            return 0;
        }
        else if (*front == -1)
            *front = *rear = 0;
        else
            (*front)--;
        Queue[*front] = item;
        return 1;
    }
    else
    {
        if ((*front == 0 && *rear == Q_Size - 1) || (*front - 1 == *rear))
        {
            printf("\nOperation Can not Perform...\nCheck For Last..!!");
        }
        else if (*front == 0)
        {
            *front = Q_Size - 1;
        }
        else
            (*front)--;
        Queue[*front] = item;
        return 1;
    }
}

int DELETE_LAST(int Queue[], int Q_Size int *front, int *rear, char *Q_Type)
{
    if (!IS_UNDERFLOW(*rear))
    {
        int x = *rear;
        if (strcmp(Q_Type, "NORMAL") == 0)
        {
            /* code */
            if (*rear - 1 == *front)
                *front = *rear = -1;
            else
                --(*rear);
        }
        else
        {
            if (*rear - 1 == *front)
            {
                *rear = *front = -1;
            }
            else if (*rear == 0 && *front > *rear)
                *rear = Q_Size - 1;
            else
                --(*rear);
        }
        printf("\n%d Deleted....", Queue[x]);
        return Queue[x];
    }
    return 0;
}

// DISPLAY

void DISPLAY(int Queue[], int front, int rear, int Size, char *Q_Type)
{
    if (!IS_UNDERFLOW(front))
    {
        printf("\n----------------------------------------------------------------------------------\n| ");
        if (!strcmp(Q_Type, "NORMAL"))
        {
            for (; front <= rear; front++)
            {
                /* code */
                printf(" %d |", Queue[front]);
            }
        }
        else if (!strcmp(Q_Type, "CIRCULAR"))
        {
            // from front to Size
            if (front > rear)
            {
                for (int i = 0; i < front; i++)
                {
                    /* code */
                    printf(" %d |", Queue[i]);
                }
                for (int i = front; i < Size; i++)
                {
                    /* code */
                    printf(" %d |", Queue[i]);
                }
            }
            else
            {
                for (; front <= Size - 1; front++)
                {
                    /* code */
                    printf(" %d |", Queue[front]);
                }
            }
        }
        printf("\n----------------------------------------------------------------------------------\n");
    }
}