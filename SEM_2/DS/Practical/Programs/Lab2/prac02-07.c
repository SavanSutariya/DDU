#include<stdio.h>
#include<string.h>
void coppyy(char *str, char *dest){
    for(int i=0; i<strlen(str);i++){
        *(dest+i) = *(str+i);
    }
}
int main(){
    char *str1,c[100], c2[100];
    str1 = c;
    printf("Enter string 1");
    scanf("%s",str1);
    coppyy(str1, c2);
    printf("Copied string : %s",c2);
    return 0;
}