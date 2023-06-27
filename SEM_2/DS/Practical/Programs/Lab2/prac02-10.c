#include<stdio.h>
#include<string.h>
void shiftStr(char *str){
    int i;
    for(i=0; i<strlen(str)-1; i++){
        str[i] = str[i+1];
    }
    str[i] = '\0';
}
void removeChar(char *str, char ch){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i] == ch){
            shiftStr(&str[i]);
            i--;
            len--;
        }
    }
}
int main(){
    char str[20],ch;
    printf("Enter a strig : ");
    scanf("%[^\n]s",str);
    printf("Enter a character to remove : ");
    scanf(" %c",&ch);
    removeChar(str,ch);
    printf("%s\n",str);
}