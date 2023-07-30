#include <stdio.h>

int LinearSearch(int arr[],int size,int key){
	for(int i=0; i<size; i++){
		if(arr[i]==key)
			return i;
	}
	return -1;
}

int BinarySearch(int arr[],int size,int key){
	int start=0;
	int end=size-1;

	while(start<=end){
		int mid=start+(end-start)/2;

		if(arr[mid]==key)
			return mid;
		else if(arr[mid] > key)
			end=mid-1;
		else
			start=mid+1;
	}
	return start;
}
int main(){
	// int size;
	// printf("Enter the Size of Arrays : \n");
	// scanf("%d",&size);
	// int arr[size];

	// printf("Enter the Value in to Arrays : \n");
	// for(int i=0; i<size; i++){
	// 	scanf("%d",&arr[i]);
	// }
	int arr[]={10,20,30,40,50};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=40;

	printf("Value will be available on This Index : %d\n",LinearSearch(arr,n,key));
	printf("Value will be available on This Index : %d\n",BinarySearch(arr,n,key));
	// printf("Enter the Key to Want Search : ");
	// scanf("%d",&key);
	// int n;
	// printf("Enter the Number to Perform Perticular Searching Algorithm \n Zero (0) For Linear Search \n One (1) For Binary Search\n");
	// scanf("%d",&n);

	// switch(n){
	// case 0:
	// 	printf("Value will be available on This Index : %d\n",LinearSearch(arr,size,key));
	// 	break;
	// case 1:
	// 	printf("Value will be available on This Index : %d\n",BinarySearch(arr,size,key));
	// 	break;

	// default:
	// 	printf("You select wrong number : ");
	// 	break;
	// }
	return 0;
}