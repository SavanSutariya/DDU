struct node{
    int value;
    struct node *next;
};
struct linklist{
    struct node *start;
};
struct node* new_node(){
    return (struct node *)malloc(sizeof(struct node));
}
void insertAtFirst(struct linklist *l, int value){
    if (l->start == 0){
        // list is still empty
        l->start = new_node();
        l->start->value = value;
    }
    else{
        // Insert before first node
        struct node *new = new_node();
        new->value = value;
        new->next = l->start;
        l->start = new;
    }
}
void insertAtLast(struct linklist *l, int value){
    if(l->start == 0){
        insertAtFirst(l,value);
    }
    else{
        struct node *tmp=l->start; //new tmp to traverse
        while(tmp->next != NULL){
            // point tmp to last element in the list
            tmp = tmp->next;
        }
        tmp->next=new_node();
        tmp->next->value = value;
    }
}
int insertAtSpecific(struct linklist *l,int value,int pos){
    struct node *tmp=l->start;
    for(int i=0; i<pos-1; i++){
        //until it gets the previous node of that position
        if(tmp->next != NULL){
            tmp = tmp->next;
        }
        else{
            //if gets null value before that position
            printf("\nInvalid position");
            return 0;
        }
    }
    //inserting after pos-1 th node
    struct node *new = new_node();
    new->value = value;
    new->next = tmp->next;
    tmp->next = new;
    return 1;
}

void deleteFirst(struct linklist *l){
    if(l->start == NULL){
        printf("\nEmpty list");
    }
    else{
        struct node *tmp=l->start;
        l->start = l->start->next;
        printf("\nDeleted |%d|%p|",tmp->value,tmp->next);
        free(tmp);
    }
}

void display(struct linklist *l){
    struct node *tmp=l->start;
    printf("\nList : ");
    while(tmp->next != NULL){
        printf(" -> |%d|%p|",tmp->value,tmp->next);
        tmp= tmp->next;
    }
    printf(" -> |%d|%p|",tmp->value,tmp->next); //last node
}