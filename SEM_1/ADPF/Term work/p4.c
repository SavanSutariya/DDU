#include<stdio.h>
int main(){
    char a,b;
    scanf("%c",&a);
    int max = 1;
    int cnt = 1;
    while(b!='\n'){
        scanf("%c",&b);
        if (a==b){
            cnt++;
        }
        else{
            if(max<cnt){
                max = cnt;
            }
            cnt = 1;
            a = b;
        }
        //printf("%c - %c - %d\n",a,b,cnt);
    }
    printf("%d %d",max, 4%5);
    return 0;   
}