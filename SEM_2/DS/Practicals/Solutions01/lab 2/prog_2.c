//  Write a C program to compare two strings using pointers.


#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "abcd";
    char str2[] = "mcaddu";

    char *ptr1 = str1;
    char *ptr2 = str2;
    int flag = 0;

    if (strlen(str1) == strlen(str2))
    {
        for(int i = 0; i < strlen(str1); i++)
        {
            if (ptr1[i] == ptr2[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
    }
    if (flag == 1)
    {
        printf("Both String is same");
    }
    else
    {
        printf("Both String are diffrent");
    }

    return 0;
}