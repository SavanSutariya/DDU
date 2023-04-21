#include <stdio.h>
#include <ctype.h>
#include "int_stack.c"
int eval(char *expression){
    struct int_stack s;
    s.top = -1;
    for(int i=0;i<expression[i]!='\0';i++){
        if(isdigit(expression[i])){
            push(&s, expression[i]-'0');
        }
        else if(expression[i] == ' '){
            continue;
        }
        else{
            printf("\nOperator %c", expression[i]);
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            if(expression[i] == '+'){
                push(&s, operand1 + operand2);
            }
            else if(expression[i] == '-'){
                push(&s, operand1 - operand2);
            }
            else if(expression[i] == '*'){
                push(&s, operand1 * operand2);
            }
            else if(expression[i] == '/'){
                push(&s, operand1 / operand2);
            }
            else{
                printf("Invalid Expression!\n");
                return 0;
            }
        }
    }
    return pop(&s);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", expression);
    printf("\nanswer : %d",eval(expression));
    return 0;
}

// output[0]:
// Enter postfix expression: 12+3*
// Operator +
// answer : 9

// output[1]:
// Enter postfix expression: 12+3*4+
// Operator +
// Operator *
// answer : 13

// output[2]:
// Enter postfix expression: 12+3*4+5-
// Operator +
// Operator *
// Operator +
// answer : 8

