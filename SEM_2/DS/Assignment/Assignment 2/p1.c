#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
void subsets(node *list, int n){
    int total = 1<<n;
    for(int i=0; i< total;i++){
        printf("\n{ ");
        node *head = list;
        for(int j=0; j<n; j++){
            // printf("%d ",(i&(1<<j))?1:0);
            (i&(1<<j))?(printf("%d ",head->val)):0;
            head = head->next;
        }
        printf("}");
    }
}
int main(){
    node *list = NULL;
    int n;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(int i=0;i<n;i++){
        int no;
        scanf("%d",&no);
        insert(&list,no);
    }
    subsets(list,n);
    return 0;
}