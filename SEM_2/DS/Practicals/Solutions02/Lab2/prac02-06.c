#include<stdio.h>
#include<string.h>
void coppyy(int *arr,int size, int *dest){
    for(int i=0; i<size;i++){
        *(dest+i) = *(arr+i);
    }
}
int main(){
    int N,M;
    printf("Size of array 1 : ");
    scanf("%d",&N);
    printf("Size of array 2 : ");
    scanf("%d",&M);
    if(N<=M){
        int arr1[N],arr2[M];
        printf("Enter %d values : ",N);
        for(int i=0; i<N; i++){
            scanf("%d",&arr1[i]);
        }
        coppyy(arr1, N, arr2);
        for(int i=0; i<N; i++)
            printf("%d ",arr2[i]);
    }
    else{
        printf("Array 1 should be smaller or equal to array 2");
    }
    return 0;
}