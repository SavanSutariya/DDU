#include<stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("\n[Inside function]Swap\na=%d - b=%d\n",*a,*b);
}
void swap_v(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	printf("\n[Inside function]Swap\na=%d - b=%d\n",a,b);
}
int main(){
	int a,b;
	printf("Enter a and b : ");
	scanf("%d %d",&a,&b);
	printf("--Pass by value--\n");
	printf("a=%d - b=%d",a,b);
	swap_v(a,b);
	printf("\nSwap\na=%d - b=%d\n",a,b);
	printf("\n--Pass by reference--\n");
	printf("a=%d - b=%d",a,b);
	swap(&a,&b);
	printf("\nSwap\na=%d - b=%d\n",a,b);
}
