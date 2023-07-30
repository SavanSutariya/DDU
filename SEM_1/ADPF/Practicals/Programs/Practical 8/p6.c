#include<stdio.h>
#include<ctype.h>
int main(){
   char str[100];
   gets(str);
   printf("%s",str);
   for(int i=0;str[i]!=0;i++){
       if(!isalpha(str[i])){
           for (int j=i;str[j]!=0;j++){
               str[j]=str[j+1];
           }
       }
   }
   printf("\n %s",str);
}