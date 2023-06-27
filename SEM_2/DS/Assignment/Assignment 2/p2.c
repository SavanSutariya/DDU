#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
void removeDuplicates(node **head){
    if(*head == NULL){
        printf("\n(empty:rmdpl)");
        return;
    }
    node *tmp = *head;
    while(tmp != NULL){
        node *n = tmp->next;
        node *prev = tmp;
        while(n != NULL){
            // printf("\ntmp[%d] - n[%d]",tmp->val,n->val);
            if(tmp->val == n->val){
                if(n->next == NULL){
                    node *d = n;
                    prev->next = NULL;
                    n = NULL;
                    free(d);
                }
                else {
                    node *d = n;
                    prev->next = n->next;
                    n = n->next;
                    free(d);
                }
            }
            else {
                prev = n;
                n = n->next;
            }
        }
        tmp = tmp->next;
    }
}

int main(){
    node *list=NULL;
    int n;
    printf("Enter the number of inputs : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        insert(&list,val);
    }
    removeDuplicates(&list);
    display(list);
    return 0;   
}





