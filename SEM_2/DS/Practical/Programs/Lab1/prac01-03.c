#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int *ptr, **ptr2;
	ptr=&n;
	ptr2=&ptr;
	printf("n=%d -- ptr=%p -- ptr2=%p -- *ptr=%d -- *ptr2=%p -- **ptr2=%d",n,ptr,ptr2,*ptr,*ptr2,**ptr2);
	return 0;
}
