// Write a C program to copy a string to another without using strcpy function. Use pointers for
// both the strings.

#include<stdio.h>
#include<string.h>

int main()
{
    char str1[] = "Prathvik";
    char str2[20];

    char *ptr = str1;
    
    for(int i = 0; i <= strlen(str1); i++)
    {
        str2[i] = ptr[i];
    }

    printf("%d --- %d", sizeof(str1), sizeof(str2));
    printf("%s", str2);
}