#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char val;
    struct node *next;
}node;
typedef struct linklist{
    node *head;
}linklist;

node *createNode(char val){
    node *new = (node *)malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    return new;
}

void push(linklist *l,char val){
    node *new = createNode(val);
    if(l->head == NULL){
        l->head = new;
        return;
    }
    node *tmp = l->head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = new;
}

char pop(linklist *l){
    if(l->head == NULL){
        printf("Empty");
        return -1;
    }
    node *tmp = l->head;
    char val = tmp->val;
    l->head = tmp->next;
    free(tmp);
    return val;
}

char peek(linklist *l){
    if(l->head == NULL){
        printf("Empty");
        return -1;
    }
    node *tmp = l->head;
    char val = tmp->val;
    return val;
}

int isEmpty(linklist *l){
    if(l->head == NULL){
        return 1;
    }
    return 0;
}

int isOperand(char c){
    if((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z' )){
        return 1;
    }
    return 0;
}

int precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    return -1;
}

void infixToPostfix(char *exp){
    linklist l;
    l.head = NULL;
    int i,k;
    for(i = 0,k = -1;exp[i] != '\0';i++){
        if(isOperand(exp[i])){
            exp[++k] = exp[i];
        }
        else if(exp[i] == '('){
            push(&l,exp[i]);
        }
        else if(exp[i] == ')'){
            while(!isEmpty(&l) && peek(&l) != '('){
                exp[++k] = pop(&l);
            }
            if(!isEmpty(&l) && peek(&l) != '('){
                printf("Invalid Expression");
                return;
            }
            else{
                pop(&l);
            }
        }
        else{
            while(!isEmpty(&l) && precedence(exp[i]) <= precedence(peek(&l))){
                exp[++k] = pop(&l);
            }
            push(&l,exp[i]);
        }
    }
    while(!isEmpty(&l)){
        exp[++k] = pop(&l);
    }
    exp[++k] = '\0';
    printf("%s",exp);
}

int main(){
    char exp[100];
    scanf("%s",exp);
    infixToPostfix(exp);
    return 0;
}