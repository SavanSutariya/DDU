// Define a structure which has members that include name, idno and marks. Write a C
// program to read the information about N students and print the name and idno of the
// students having marks less then M.

#include<stdio.h>

struct student{
    char name[20];
    int idno;
    int marks;
};
int main(){

    int n, m;
    printf("Enter student size: ");
    scanf("%d", &n);

    struct student s[n];

    for(int i = 0; i < n; i++){
        printf("Enter %d student name:\n", i);
        scanf("%s", s[i].name);
        printf("Enter %d student idno:\n", i);
        scanf("%d", &s[i].idno);
        printf("Enter %d student marks:\n", i);
        scanf("%d", &s[i].marks);
    }

    printf("Enter the m marks: \n");
    scanf("%d", &m);

    for(int i = 0; i < n; i++){

        if(s[i].marks < m){
            printf("Name: %s\n", s[i].name);
            printf("IdNo: %d\n", s[i].idno);
            printf("marks: %d\n", s[i].marks);
        }
    }
    return 0;
}