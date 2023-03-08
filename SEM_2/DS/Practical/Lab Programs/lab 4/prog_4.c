// Write a program to implement following stack operations using arrays with MAX
// elements. Use integer array
// ∙ PUSH
// ∙ POP
// ∙ PEEP
// ∙ DISPLAY
// ∙ CHANGE
// ∙ IS_FULL
// ∙ IS_EMPTY

#include<stdio.h>
#include "stackint.h"

int main(){

    int n,ch, pos;
    int element;
    printf("Enter size of stack: \n");
    scanf("%d", &n);
    struct stack *s = init(n);

    do{
        printf("Select choice: \n");
        printf(" 1. push\n 2. pop\n 3. change\n 4. peak\n 5. isempty\n 6. is full\n 7. display\n 8. Exit \nEnter your choice: \n");
        scanf("%d", &ch);
        if(ch == 1){
            printf("Enter push char: \n");
            scanf("%d", &element);
            push(s, element);
        }else if(ch == 2){
            printf("%d\n",pop(s));
        }else if(ch == 3){
            printf("Enter position of stack: \n");
            scanf("%d", &pos);
            printf("Enter change char: \n");
            scanf("%d", &element);
            change(s, pos, element);
        }else if(ch == 4){
            printf("peak element is : %d\n", peak(s));
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