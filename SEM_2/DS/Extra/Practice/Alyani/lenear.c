#include<stdio.h>

int main(){
    int n;
    printf("\nEnter N :");
    scanf("%d",&n);

    int arr[n];
    printf("\nEnter Array Elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("\nEnter Element You Want to search : ");
    scanf("%d",&key);
    int flag=0;
    for(int i=0;i<n;i++){
        if(key==arr[i])
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
        printf("%d---FOUND---",key);
    else    
        printf("---NOT FOUND---");

    return 0;
}