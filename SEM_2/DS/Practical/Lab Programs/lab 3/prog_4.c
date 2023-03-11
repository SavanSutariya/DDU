// Write a C program to accept a number n from the user and create an array of size n
// using dynamic memory allocation. Accept and store values in the array. Now take
// another number m from the user and revise the array size using dynamic memory
// allocation. Accept and store values in the revised array. Find the sum of all elements in
// both cases.


#include<stdio.h>
#include<stdlib.h>

struct employee{
    int empid, age;
    char empname[25];
};

int main(){
    int count = 1;
    int ch;
    int i = 0;
    struct employee *e = (struct employee *) malloc(count * sizeof(struct employee));
   
    
    do{
        count++;
        printf("ENter id, name, age of employee: \n");
        scanf("%d %s %d", &e[i].empid, e[i].empname, &e[i].age);
        printf("Enter choice 1 for count. and 2 for exit: \n");
        scanf("%d", &ch);
        if(ch == 1){
            e = (struct employee *) realloc(e, count * sizeof(struct employee));
            i++;
        }
    }while (ch != 2);

    for (int i = 0; i < count-1; i++)
    {
        printf("Id: %d  name: %s  age:%d\n", e[i].empid, e[i].empname, e[i].age);
    }
    free(e);
    
    
    return 0;
}