#include<stdio.h>
#include "char_stack.c"

int main() {
    struct char_stack s;
    s.top = -1;
    char str[MAX];
    printf("Enter string: ");
    scanf(" %[^\n]s", str);

    for(int i=0;str[i]!='\0';i++){
        push(&s, str[i]);
    }
    for(int i=0;str[i]!='\0';i++){
        str[i] = pop(&s);
    }
    printf("Reversed string: %s", str);
    return 0;
}

// output[0]:
// Enter string: Hello World
// Reversed string: dlroW olleH

// output[1]:
// Enter string: I am a student
// Reversed string: tnemudets a ma I

// output[2]:
// Enter string: savan
// Reversed string: navas