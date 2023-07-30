#include <stdio.h>
#include "char_stack.c"

int main() {
    struct char_stack s;
    s.top = -1;
    push(&s, 'a');
    push(&s, 'b');
    push(&s, 'c');
    display(&s);
    change(&s, 1, 'd');
    display(&s);
    pop(&s);
    display(&s);
    printf("Is Full: %d\n", is_full(&s));
    printf("Is Empty: %d\n", is_empty(&s));
    printf("peep 2: %c\n", peep(&s,1)); 

    return 0;
}

// output:
// Stack: c b a
// Stack: c d a
// Stack: c d
// Is Full: 0
// Is Empty: 0
// peep 2: d