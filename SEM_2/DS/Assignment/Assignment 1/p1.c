#include "int_stack.h"
// Write a program to sort a stack using a temporary stack. Build a stack as input
// from the user
int main(){
    int_stack inputStack, tmp;
    initIntStack(&inputStack);
    initIntStack(&tmp);
    int n;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    printf("Enter the elements of the stack: ");
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        push(&inputStack, x);
    }
    while(inputStack.top != -1){
        int x = pop(&inputStack);
        while(tmp.top != -1 && x<peek(&tmp)){
            push(&inputStack,pop(&tmp));
        }
        push(&tmp,x);
        // printf("\nPushed %d",x);
    }
    printf("Sorted : ");
    display(&tmp);
    

}