#include <stdio.h>
struct student{
	char name[10];
	int id;
	float marks[5];
};
void read_stud(struct student *s){
	printf("Enter name of student : ");
	scanf("%s",s->name);
	printf("Enter id of %s : ",s->name);
	scanf("%d",&s->id);
	for(int i=0; i<5; i++){
		printf("Enter marks %d: ",i);
		scanf("%f",&s->marks[i]);
	}
}
float total_marks(float marks[5]){
	float sum = 0;
	for (int i=0; i<5; i++){
		sum += marks[i];
	}
	return sum;
}
float percentage(float marks[5]){
	return total_marks(marks)/5;
}
void print_stud(struct student s){
	printf("\nName : %s",s.name);
	printf("\tId : %d",s.id);
	printf("\tMarks : ");
	for(int i=0; i<5; i++)
		printf("%.2f ",s.marks[i]);
	printf("\tTotal : %.2f",total_marks(s.marks));
	printf("\tPercentage : %.2f",percentage(s.marks));
}
int main(){
	printf("How many students do you want to enter?");
	int N;
	scanf("%d",&N);
	struct student s[N];
	for(int i=0; i<N; i++){
		read_stud(&s[i]);
	}
	for(int i=0; i<N; i++){
		print_stud(s[i]);
	}
}
