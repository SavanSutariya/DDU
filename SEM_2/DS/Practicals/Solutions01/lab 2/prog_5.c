//  Write a C Program to check whether the string entered by the user is a palindrome string or not
// using a pointer.

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "ABCDfCBA";

    char *ptr = str1;
    int start = 0;
    int end = strlen(str1) - 1;
    int flag = 0;

    while (start <= end)
    {

        if (ptr[start] == ptr[end])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        start++;
        end--;
    }

    if (flag == 1)
    {
        printf("String is palindrom");
    }
    else
    {
        printf("String is not a pelindrom");
    }

    return 0;
}