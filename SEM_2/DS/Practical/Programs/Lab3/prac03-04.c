#include<stdio.h>
#include<stdlib.h>
struct employee{
    int empID;
    char name[20];
    int age;
};
int main(){
    int n;
    scanf("%d",&n);
    struct employee *emp = (struct employee *)malloc(n*sizeof(struct employee));
    if(emp == NULL){
        printf("No available space!!");
        return 0;
    }
    for(int i=0; i<n; i++){
        printf("Enter id");
        scanf("%d",&emp[i].empID);
        printf("Enter name");
        scanf(" %[^\n]s",emp[i].name);
        printf("Enter age");
        scanf("%d",&emp[i].age);
    }
    for(int i=0; i<n; i++){
        printf("\nId : %d",emp[i].empID);
        printf("\nName : %s",emp[i].name);
        printf("\nAge : %d",emp[i].age);
    }
    return 0;
}