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
    int n;
    printf("\nEnter n");
    scanf("%d",&n);
    int *arr = (int *)calloc(n,sizeof(int));
    if(arr == NULL){
        printf("No available space!!");
        return 0;
    }
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nSum : %d",sum(arr,n));
    free(arr);
    return 0;
}