// Write a program to implement following character stack operations using arrays with
// MAX elements. Use a Character array. [Try to create generic function so that it can be
// reused for later programs]
// ∙ PUSH
// ∙ POP
// ∙ PEEP
// ∙ DISPLAY
// ∙ CHANGE
// ∙ IS_FULL
// ∙ IS_EMPTY

#include<stdio.h>
#include "stackcharacter.h"

int main(){

    int n,ch, pos;
    char element;
    printf("Enter size of stack: \n");
    scanf("%d", &n);
    struct stack *s = init(n);

    do{
        printf("Select choice: \n");
        printf(" 1. push\n 2. pop\n 3. change\n 4.peak\n 5. isempty\n 6. is full\n 7. display\n 8. Exit \nEnter your choice: \n");
        scanf("%d", &ch);
        if(ch == 1){
            printf("Enter push char: \n");
            scanf("%s", &element);
            push(s, element);
        }else if(ch == 2){
            printf("%c\n",pop(s));
        }else if(ch == 3){
            printf("Enter position of stack: \n");
            scanf("%d", &pos);
            printf("Enter change char: \n");
            scanf("%s", &element);
            change(s, pos, element);
        }else if(ch == 4){
            printf("peak element is : %c\n", peak(s));
        }else if(ch == 5){
            if(isEmpty(s)){
                printf("Stack is Empty!!\n");
            }else{
                printf("Stack is Not Empty!!\n");
            }
        }else if(ch == 6){
            if(isFull(s)){
                printf("Stack is Full!!\n");
            }else{
                printf("Stack is Not FUll!!\n");
            }
        }else if(ch == 7){
            display(s);
        }
    }while (ch != 8);
    
    return 0;
}