// Write a program to evaluate a postfix expression. [You can use code for stack
// implementation and operation created in earlier program]


#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>

#define size 100

int top = -1;
int stack[size];

void push(int ele)
{
    if (top == size - 1)
    {
        printf("Stack is Overflow!!push\n");
        exit(1);
    }
    else
    {
        stack[++top] = ele;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is Underflow!!\n");
        exit(1);
    }
    else
    {
        return stack[top--];
    }
}
int evalute_postfix(char *expr)
{
    int i = 0;
    int val1, val2, result;

    // printf("%d", expr[i] - '0');
    while (expr[i])
    {
        if (isdigit(expr[i]))
        {
            push(expr[i] - '0');
        }
        else
        {
            val2 = pop();
            val1 = pop();

            switch (expr[i])
            {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    result = val1 / val2;
                    break;

                default:
                    printf("Invalid operation!!");
                    break;
            }
            push(result);
        }
        i++;
    }
    return pop();
}
int main()
{
    char expr[100];
    printf("Enter a PostFix Expression: \n");
    scanf("%s", expr);

    printf("Result is : %d \n", evalute_postfix(expr));
    return 0;
}