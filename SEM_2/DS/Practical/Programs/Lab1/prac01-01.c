#include <stdio.h>
struct student{
	char name[10];
	int id;
	float marks;
};
void read_stud(struct student *s){
	printf("Enter name of student : ");
	scanf("%s",s->name);
	printf("Enter id of %s : ",s->name);
	scanf("%d",&s->id);
	printf("Enter marks of %s : ",s->name);
	scanf("%f",&s->marks);
}
void print_stud(struct student s){
	printf("\nName : %s",s.name);
	printf("\tId : %d",s.id);
	printf("\tMarks : %.2f",s.marks);
}
int main(){
	printf("How many students do you want to enter?");
	int N;
	scanf("%d",&N);
	struct student s[N];
	for(int i=0; i<N; i++){
		read_stud(&s[i]);
	}
	printf("\n\n Enter Maximum Marks (M)");
	int M;
	scanf("%d",&M);
	for(int i=0; i<N; i++){
		if(s[i].marks < M){
			print_stud(s[i]);
		}
	}
}
