#include<stdio.h>
#include<stdlib.h>
int main(){
    int *arr;
    arr = malloc(5*sizeof(int)+1);
    if(arr == NULL){
        printf("No available space!!");
        return 0;
    }
    for(int i=0; i<5; i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<5; i++){
        printf("\n%d",arr[i]);
    }
    int *arr2 = realloc(arr, 6*sizeof(int));
    printf("\n\nARR1 : %p",arr);
    printf("\n\nARR2 : %p",arr2);
    return 0;
}