#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
int findMiddle(node *slow){
    node *fast=slow;
    if(fast == NULL){
        printf("Empty");
        return 0;
    }
    if(fast->next == NULL){
        return fast->val;
    }
    while(1){
        // printf("\nslow [%d] fast [%d]",slow->val,fast->val);
        fast = fast->next->next;
        if(fast==NULL || fast->next == NULL){
            return slow->val;
        }
        slow = slow->next;
    }
    return slow->val;
}

int main(int argc, char *argv[]){
    node *list=NULL;
    for(int i = 1; i<argc; i++){
        insert(&list,atoi(argv[i]));
    }
    printf("Middle element :%d",findMiddle(list));
}