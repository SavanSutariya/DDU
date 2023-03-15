//  Write a C program to count vowels and consonants in a string using a pointer

#include<stdio.h>

int main()
{
    char str[] = "hello prathvik!";
    char *ptr = str;
    int constant = 0;
    int vowel = 0;
    int i = 0;
    
    for(int i = 0; ptr[i] != '\0'; i++)
    {
        if(ptr[i] == 'a' || ptr[i] == 'e' || ptr[i] == 'i'
        || ptr[i] == 'o' || ptr[i] == 'u')
        {
            vowel++;
        }else{
            constant++;
        }
    }

    printf("%d --- %d",vowel ,constant );
    return 0;
}