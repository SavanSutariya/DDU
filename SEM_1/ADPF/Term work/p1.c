#include<stdio.h>
int f(int n){
    static int cnt = 0;
    // printf("f(%d)\n",n);
    if (n==1)
        return cnt;
    cnt++;
    if(n%2==0)
        return f(n/2);
    else
        return f(3*n+1);

}
int main(){
    int input;
    scanf("%d",&input);
    printf("%d",f(input));
}