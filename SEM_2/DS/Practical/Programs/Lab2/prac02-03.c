#include<stdio.h>
void isOddorEven(int n){
    if(n%2 == 0){
        printf("Even");
    }
    else{
        printf("Odd");
    }
}
int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    void (*funpointer)(int) = isOddorEven;
    funpointer(n);
    return 0;
}