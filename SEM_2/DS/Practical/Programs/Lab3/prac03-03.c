#include<stdio.h>
#include<stdlib.h>
int sum(int arr[],int n){
    int s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
    }
    return s;
}
int main(){
    int *arr,n,m;
    printf("Enter n :");
    scanf("%d",&n);
    arr = malloc(n*sizeof(int));
    if(arr == NULL){
        printf("No available space!!");
        return 0;
    }
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nSum(arr1)%d",sum(arr,n));
    printf("\nEnter m :");
    scanf("%d",&m);
    int *arr2 = realloc(arr, m*sizeof(int));
    if(arr2 == NULL){
        printf("No available space!!");
        return 0;
    }
    for(int i=0; i<m; i++){
        scanf("%d",&arr2[i]);
    }
    printf("\nSum(arr2)%d",sum(arr2,m));
    printf("\n\nARR1 : %p",arr);
    printf("\n\nARR2 : %p",arr2);
    return 0;
}