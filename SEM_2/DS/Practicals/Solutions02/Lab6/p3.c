// Write a program to perform sort on an integer linked list

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
int main(){
    linkedList l1;
    l1.head = NULL;
    insertAtLast(&l1,3);
    insertAtLast(&l1,5);
    insertAtLast(&l1,11);
    insertAtLast(&l1,1);
    insertAtLast(&l1,2);
    display(&l1);
    sortList(&l1);
    display(&l1);
}