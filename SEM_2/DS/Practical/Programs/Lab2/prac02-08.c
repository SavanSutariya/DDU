#include<stdio.h>
#define size 10
float Average(float *arr){
    int M;
    printf("Enter M : ");
    scanf("%d",&M);
    float sum = 0;
    for(int i=0;i<M; i++){
        sum += arr[i];
    }
    return sum/M;
}
int main(){
    float arr[size];
    printf("Enter 10 values : ");
    for(int i=0;i<size; i++){
        scanf("%f",&arr[i]);
    }
    printf("Average : %f",Average(arr));
    return 0;
}