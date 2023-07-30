// Write a C program that takes a Student structure array [ for example struct Student st[10]
// defines an array called student that consists of 10 elements. Each element is defined to be
// of the type struct Student]. The program should store marks of 5 subjects and calculate
// total and percentage. Display each subject's marks, total and percentage for all students.

#include<stdio.h>

struct student{
    int marks[3];
    float pr;
    int total;
};
int main(){
    int n = 3;
    int temp = 0;
    struct student s[n];
    for(int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++)
        {
            printf("Enter marks for subject : %d\n", i);
            scanf("%d", &s[i].marks[j]); 
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp += s[i].marks[j]; 
        }
        printf("total: %d\n", temp);
        s[i].total = temp;
        s[i].pr = (s[i].total/3);
        printf("pr: %f\n", s[i].pr);
        temp = 0;
    }
    


    

    


    return 0;
}