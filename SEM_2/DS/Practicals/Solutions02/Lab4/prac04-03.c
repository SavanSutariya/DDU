#include <stdio.h>
#include <string.h>
#include "char_stack.c"

int main() {
    char str[] = "Hello, world!";
    struct stack s;
    init(&s, strlen(str));
    for (int i = 0; i < s.size; i++) {
        push(&s, str[i]);
    }
    printf("Reversed string: ");
    while (!is_empty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");

    return 0;
}
