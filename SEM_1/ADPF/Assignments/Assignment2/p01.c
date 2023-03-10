#include<stdio.h>

int find_even(int k){
    int j=-1, cnt=0;
    do{
        scanf("%d",&j);
        if(j%2==0){
            cnt++;
            if(cnt==k){
                return j;
            }
        }
    }while(j>0);

}

int main(){
    int k;
    scanf("%d",&k);
    printf("%d",find_even(k));
}