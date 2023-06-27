// Priority queue using link list (Utilize functions)
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    int priority;
    struct node *next;
}node;
typedef struct linklist{
    node *head;
}linklist;

node *create(int val,int priority){
    node *new = (node *)malloc(sizeof(node));
    new->val = val;
    new->priority = priority;
    new->next = NULL;
    return new;
}
//insert in priority order
void enqueue(linklist *l,int val,int priority){
    node *new = create(val,priority);
    if(l->head == NULL){
        l->head = new;
        return;
    }
    node *tmp = l->head;
    if(tmp->priority > priority){
        new->next = tmp;
        l->head = new;
        return;
    }
    while(tmp->next != NULL && tmp->next->priority <= priority){
        tmp = tmp->next;
    }
    new->next = tmp->next;
    tmp->next = new;
}
//delete from front
int dequeue(linklist *l){
    if(l->head == NULL){
        printf("Empty");
        return -1;
    }
    node *tmp = l->head;
    int val = tmp->val;
    l->head = tmp->next;
    free(tmp);
    return val;
}

void display(linklist *l){
    printf("\n");
    if(l->head == NULL){
        printf("Empty");
        return;
    }
    node *tmp = l->head;
    while(tmp != NULL){
        printf("%d ",tmp->val);
        tmp = tmp->next;
    }
}

int main(){
    // menu
    linklist l;
    l.head = NULL;
    int ch,val,priority;
    while(1){
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter choice: ");        
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value and priority: ");
                scanf("%d%d",&val,&priority);
                enqueue(&l,val,priority);
                break;
            case 2:
                printf("Removed %d\n",dequeue(&l));
                break;
            case 3:
                display(&l);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}