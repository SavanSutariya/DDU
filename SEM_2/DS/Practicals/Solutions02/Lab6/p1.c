#include<stdio.h>
#include<stdlib.h>
#include "ll.h"
int main(){
    linkedList l1;
    l1.head = NULL;
    insertAtLast(&l1,3);
    deleteAtFirst(&l1);
    insertAtLast(&l1,5);
    insertAtLast(&l1,11);
    insertAtFirst(&l1,1);
    insertAtFirst(&l1,3);
    display(&l1);
    insertAtPosition(&l1,44,7);
    display(&l1);
    deleteAtFirst(&l1);
    display(&l1);
}


//output : 3 1 5 11
//         3 1 5 11 44
//         1 5 11 44 