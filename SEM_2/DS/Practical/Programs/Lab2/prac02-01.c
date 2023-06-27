#include<stdio.h>
int main(){
    char *str, c[100];
    int vovel = 0, cons=0;
    str = c;
    scanf("%s",str);
    for(int i=0; str[i]!= '\0'; i++){
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
            vovel++;
        }
        else
            cons++;
    }
    printf("\nVovels : %d and consonants : %d",vovel,cons);
    return 0;
}