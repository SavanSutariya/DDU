#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
void mergeOrdered(node **head1, node *head2){
    //inserts elements of head2 into head1 one by one useing insert method
    while(head2 != NULL){
        insertOrdered(head1,head2->val);
        head2 = head2->next;
    }
}

int main(int argc, char *argv[]){
    node *list1 = NULL;
    node *list2 = NULL;
    for(int i=1; i<argc/2+1; i++){
        insertOrdered(&list1,atoi(argv[i]));
    }
    for(int i=argc/2+1; i<argc; i++){
        insertOrdered(&list2,atoi(argv[i]));
    }
    display(list1);
    display(list2);
    mergeOrdered(&list1,list2);
    printf("\nMerged");
    display(list1);
    return 0;
}