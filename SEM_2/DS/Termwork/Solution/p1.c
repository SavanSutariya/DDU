#include<stdio.h>
#include<stdlib.h>
#include"intlist.h"
void appendToFirstFromLast(linklist *l){
    if(l->head == NULL || l->head->next == NULL){
        return;
    }
    node *tmp = l->head;
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    tmp->next->next = l->head;
    l->head = tmp->next;
    tmp->next = NULL;
}
int main(){
    linklist l1;
    l1.head = NULL;
    while(1){
        int val;
        scanf("%d",&val);
        if(val == -1)
            break;
        insert(&l1,val);
    }
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        appendToFirstFromLast(&l1);
    display(&l1);
    return 0;
}