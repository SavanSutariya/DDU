#include<stdio.h>
#include<string.h>
int areSame(char *str1, char *str2){
    if(strlen(str1) == strlen(str2)){
        for(int i=0; i<=strlen(str1); i++){
            if(*(str1+i)!=*(str2+i)){
                return 0;
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}
int palindrome(char *str){
    int N = strlen(str);
    char rev[100]; 
    for(int i=0; i<N; i++){
        *(rev+(N-i-1)) = *(str+i);
    }
    return areSame(str,rev);
}
int main(){
    char *str1,c[100];
    str1 = c;
    printf("Enter string 1");
    scanf("%s",str1);
    if(palindrome(str1)){
        printf("Palindrome");
    }
    else{
        printf("Not palindrome");
    }
    return 0;
}