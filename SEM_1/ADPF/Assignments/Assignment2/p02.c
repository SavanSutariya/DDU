#include<stdio.h>
int main(){
    float price[365];
    for(int i = 0; i<=365; i++){
        scanf("%f", &price[i]);
        if(price[i] == -1)
            break;
    }
    int i = 2;
    while(price[i]!=-1){
        printf("%.1f ",(price[i]+price[i-1]+price[(i++)-2])/3);
    }

}