#include "char_stack.h"
#include <stdio.h>
#include <string.h>
int main(){
    char_stack main, aux;
    initCharStack(&main,100);
    initCharStack(&aux,100);
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    int n = strlen(str);
    for(int i=0; i<n; i++){
        if(i==0){
            push(&main, str[i]);
        }else{
            if(str[i]>=peek(&main)){
                push(&main, str[i]);
            }else{
                while(main.top != -1 && str[i]<peek(&main)){
                    push(&aux, pop(&main));
                }
                push(&main, str[i]);
                while(aux.top != -1){
                    push(&main, pop(&aux));
                }
            }
        }
    }
    printf("Sorted: ");
    for(int i=0; i<= main.top; i++){
        printf("%c", main.arr[i]);
    }
}