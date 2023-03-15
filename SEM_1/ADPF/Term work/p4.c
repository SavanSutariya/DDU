// #include<stdio.h>
// int main(){
//     char a,b;
//     scanf("%c",&a);
//     int max = 1,run = 1;
//     while(b!='\n'){
//         scanf("%c",&b);
//         if (a==b){
//             run++;
//         }
//         else{
//             if(max<run){
//                 max = run;
//             }
//             run = 1;
//             a = b;
//         }
//         //printf("%c - %c - %d\n",a,b,run);
//     }
//     printf("%d",max);
//     return 0;   
// }
#include<stdio.h>
int main(){
    char str[100];
    scanf("%s",str);
    int max = 1,run = 1;
    for(int i=0; str[i]!='\0'; i++){
        if (str[i]==str[i+1])
            run++;
        else{
            if(max<run)
                max = run;
            run = 1;
        }
        //printf("%c - %c - %d\n",a,b,run);
    }
    printf("%d",max);
    return 0;   
}