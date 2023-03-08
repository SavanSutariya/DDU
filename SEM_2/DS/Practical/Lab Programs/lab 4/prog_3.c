// Write a program to reverse the string using stack operations [You can use code for stack
// implementation and operation created in earlier program]

#include<stdio.h>
#include<string.h>
#include "stackcharacter.h"

int main(){

    char str[25];

    printf("Enter string: \n");
    scanf("%s", str);

    struct stack *s = init(10);
    for (int i = 0; i < strlen(str); i++)
    {
        push(s, str[i]);
    }

    for(int i = 0; i < strlen(str); i++){
        printf("%c ", pop(s));
    }
    


    return 0;
}