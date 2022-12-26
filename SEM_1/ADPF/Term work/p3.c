// Anagram
#include <stdio.h>
#include <string.h>
int main()
{
    char s[100], t[100];
    int i, j, ls, lt, match = 0, cnt=0;
    scanf("%s", s);
    scanf("%s", t);
    ls = strlen(s);
    lt = strlen(t);
    if (ls != lt){
        printf("-1"); 
    }
    else{
        for (i = 0; i < ls; i++){
            for (j = 0; j < lt; j++){
                if (s[i] == t[j]){
                    t[j] = '\0';
                    if(i == j)
                        match++; // count the number of matching positions
                    // printf("%c <- s[%d] %c <- t[%d]\n",s[i],i,t[j],j);
                    cnt++; // count the number of characters matched
                    break;
                }
            }
        }
        if(cnt == ls)
            printf("%d", match);
        else
            printf("-1");
    }
    return 0;
}