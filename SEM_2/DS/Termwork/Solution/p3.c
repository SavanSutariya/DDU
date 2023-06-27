#include<stdio.h>
#include<stdlib.h>
#include"intlist.h"
void interUnion(linklist *l1, linklist *l2, linklist *i, linklist *u){
    if(l1->head == NULL && l2->head == NULL)
        return;
    node *tmp1 = l1->head;
    //first list + intersacting into union
    while(tmp1!=NULL){
        node *tmp2 = l2->head;
        while(tmp2!=NULL){
            if(tmp1->val == tmp2->val)
                insert(i,tmp1->val);
            tmp2=tmp2->next;
        }
        insert(u,tmp1->val);
        tmp1=tmp1->next;
    }
    //remaining union from list2
    tmp1 = l2->head;
    while(tmp1 != NULL){
        node *tmp2 = i->head;
        short flag = 0;
        while(tmp2 != NULL){
            if(tmp1->val == tmp2->val){
                flag=1;
                break;
            }
            tmp2 = tmp2->next;
        }
        if(!flag)
            insert(u,tmp1->val);
        tmp1 = tmp1->next;
    }
}
int main(){
    linklist l1,l2,unionlist,interlist;
    l1.head = NULL;
    l2.head = NULL;
    unionlist.head = NULL;
    interlist.head = NULL;
    while(1){
        int n;
        scanf("%d",&n);
        if(n==-1)
            break;
        insert(&l1,n);
    }
    while(1){
        int n;
        scanf("%d",&n);
        if(n==-1)
            break;
        insert(&l2,n);
    }
    interUnion(&l1,&l2,&interlist,&unionlist);
    printf("intersection list : ");
    display(&interlist);
    printf("\nunion list : ");
    display(&unionlist);
    return 0;
}