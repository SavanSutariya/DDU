#include <stdio.h>

void increment(int *num) {
    *num += 2;
}

void decrement(int *num) {
    *num -= 2;
}

void apply_operation(int num, void (*operation)(int *)) {
    operation(&num);
    printf("Result: %d\n", num);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int choice;
    printf("Do you want to add or subtract? (1 = add, 2 = subtract): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        apply_operation(num, &increment);
    } 
    else if (choice == 2) {
        apply_operation(num, &decrement);
    } 
    else {
        printf("Invalid choice.\n");
    }
    
    return 0;
}
