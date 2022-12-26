#include <stdio.h>
#include <math.h>
int count_distinct(int *arr, int n){
    int i,j,cnt=0;
    for(i=0; i<n; i++){
        for(j=0; j<i; j++){
            if (arr[i] == arr[j])
            {
                break;
            }
            
        }
        if(i==j){
            cnt++;
        }
    }
    return cnt;

}
int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    int arr[N];
    for (int i=0; i<N; i++){
        // printf("%d\n",((M*(int)pow(2,i))%N));
        arr[i] = (M*(int)pow(2,i))%N;
    }
    printf("%d",count_distinct(arr,N));
    return 0;
}


/*
In this question, you are given two positive integers M and N, where M
< N. You may assume that N is less than or equal to 100.
The orbit of M with respect to N is defined to be the sequence
M, (2*M) mod N, (2^2*M) mod N, ...
There are at most N elements in the sequence, but for some M, the number of
elements in this sequence may be fewer.
You have to output the maximum number of distinct integers in the
orbit of M.
For example, if M=5 and N=8, then the orbit of 5 with respect to 8 is
5, 2*5 mod 8, 4*5 mod 8, 8*5 mod 8
which is equal to
5, 2, 4, 0.
Hence the number of distinct integers in the orbit of 5 is 4.
#include<stdio.h>
int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    int arr[N];
    for(int i=0;i<N;i++){
        arr[i] = 0;
    }
    int cnt = 0;
    int a = M;
    while(arr[a]==0){
        arr[a] = 1;
        cnt++;
        a = (2*a)%N;
    }
    printf("%d",cnt);
    return 0;
}
*/