#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * nextAdd;
}*head=NULL;

void insfirst(){
    struct Node *newNode=malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("\nInsertion not possible---");
        return ;
    }
    printf("\nEnter Data : ");
    scanf("%d",&newNode->data);
    newNode->nextAdd=NULL;
    if(head==NULL){
        head=newNode;
    }else{
         newNode->nextAdd=head;
         head=newNode;
     }
    
}
void inslast(){
    struct Node *newNode=malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("\nInsertion not possible---");
        return ;
    }
    printf("\nEnter Data : ");
    scanf("%d",&newNode->data);
}
void display(){
    if(head==NULL){
        printf("\nList is empty");
    }else{
        struct Node *temp=head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->nextAdd;
        }
    }
}

int main(){
    // struct Node *head;
    // struct Node *sec;
    // struct Node *third;
    // struct Node *frth;
    // struct Node *ffth;

    // head=malloc(sizeof(struct Node));
    // sec=(struct Node *)malloc(sizeof(struct Node));
    // third=(struct Node *)malloc(sizeof(struct Node));
    // frth=(struct Node *)malloc(sizeof(struct Node));
    // ffth=(struct Node *)malloc(sizeof(struct Node));

    // head->data=10;
    // head->nextAdd=sec;

    // sec->data=20;
    // sec->nextAdd=third;

    // third->data=30;
    // third->nextAdd=frth;

    // frth->data=40;
    // frth->nextAdd=ffth;

    // ffth->data=50;
    // ffth->nextAdd=NULL;

    insfirst();
    insfirst();
    insfirst();
    insfirst();
    display();
    return 0;
}