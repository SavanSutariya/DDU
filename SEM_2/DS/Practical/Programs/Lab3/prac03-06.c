#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int isOdd(int n){
    return n%2;
}
int main(){
    int n;
    printf("\nEnter n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<n-1; i++){
        if(isOdd(i)){
            if(arr[i]<arr[i+1]){
                swap(&arr[i],&arr[i+1]);
            }
        }
        else{
            if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1]);
            }
        }
    }
    printf("\nArray : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}