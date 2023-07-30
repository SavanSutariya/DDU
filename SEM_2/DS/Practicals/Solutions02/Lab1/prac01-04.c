#include<stdio.h>
int main(){
	int a[15] = {2,3,4,5,6,7,8,1,12,23,34,54,43,54,21},*ptr;
	for(int i=0; i<15; i++){
		scanf("%d",&a[i]);
	}
	ptr = a;
	printf("\nBase address: %p",a);
	for(int i=0; i<15; i++){
		printf("\n%d",*(ptr+i));
	}
}
