#include<stdio.h>
#include<string.h>
#include "int_stack.c"
int main(){
    char exp[] = "456*+";
    struct stack eval;
    eval.top = -1;
    eval.arr = (int *)malloc(sizeof(int)*size);
    char op2, op1;
    for(int i=0; i<sizeof(exp)-1; i++){
        switch(exp[i]){
            case '+':
                op2 = pop(&eval);
                op1 = pop(&eval);                
                push(&eval, op1+op2);
                break;
            case '-':
                op2 = pop(&eval);
                op1 = pop(&eval);
                push(&eval, op1-op2);
                break;
            case '*':
                op2 = pop(&eval);
                op1 = pop(&eval);
                push(&eval, op1*op2);
                break;
            case '/':
                op2 = pop(&eval);
                op1 = pop(&eval);
                push(&eval, op1/op2);
                break;
            default:
                push(&eval,exp[i]-'0');
        }
    }
    printf("\n\n\nAnswer : %d",pop(&eval));
    
    return 0;
}