#include<stdio.h>
int in_array(int n, int arr[],int l){
    for(int i=0; i<l; i++){
        if(n==arr[i])
            return 1;
    }
    return 0;
}
int sort(int a[],int l){
    for(int i=0; i<l-1; i++){

    }
}
int main(){
    int n1;
    scanf("%d",&n1);
    int a1[n1];
    for(int i=0; i<n1; i++){
        scanf("%d",&a1[i]);
    }
    int n2;
    scanf("%d",&n2);
    int a2[n2];
    for(int i=0; i<n2; i++){
        scanf("%d",a2[i]);
    }
    return 0;
}