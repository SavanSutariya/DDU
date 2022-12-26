#include<stdio.h>
#include<ctype.h>
int main(){
    char ch;
    short int bit=0;
    printf("%d",ch);
    int cnt=0;
    while(ch!='~'){
        ch = getchar();
        if (ch==' ' || ch=='\t' || ch=='.' || ch==',' || ch==';' || ch=='\n'){
            bit=0;
        }
        else {
            if (bit == 0 && isalnum(ch)){
                cnt++;
                bit = 1;
            }
        }
    }
    printf("%d",cnt);
}