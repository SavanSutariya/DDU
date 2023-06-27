#include<stdio.h>
#include<string.h>
int main(){
    char *str1,*str2, c[100], c2[100];
    str1 = c;
    str2 = c2;
    printf("Enter string 1");
    int i=0;
    char ch;
    do{
        scanf("%c",&ch);
        str1[i] = ch;
        i++;
    }while(ch!='\n');
    str1[i] = '\0';
    i = 0;
    printf("Enter string 2");
    do{
        scanf("%c",&ch);
        str2[i] = ch;
        i++;
    }while(ch!='\n');
    str2[i] = '\0';
    if(strlen(str1) == strlen(str2)){
        for(int i=0; i<=strlen(str1); i++){
            if(*(str1+i)!=*(str2+i)){
                printf("Not same");
                return 0;
            }
        }
        printf("Same");
    }
    else{
        printf("Not same");
    }
    return 0;
}