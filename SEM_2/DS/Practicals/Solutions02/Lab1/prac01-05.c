#include<stdio.h>
int main(){
	int arr[5], *ptr_arr[5];
	printf("Enter 5 numbers : ");
	for (int i=0; i<5; i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0; i<5; i++){
		ptr_arr[i] = &arr[i];
	}
	for(int i=0; i<5; i++){
		printf("\n%p --> %d",ptr_arr[i],*ptr_arr[i]);
	}
}
