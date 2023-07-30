#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str1[100], str2[100];
    int choice, len, cmp;
    printf("Enter a string: ");
    gets(str1);
    while (1)
    {
        printf("\n1. String Length \t 2. String Copy \t 3. String Compare \t 4. String Concat \t 5. Upper Case \t 6. Lower Case \t 7. Print \t 8. Exit \t Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            len = strlen(str1);
            printf("Length of string is %d", len);
            break;
        case 2:
            strcpy(str2, str1);
            printf("String copied successfully");
            break;
        case 3:
            cmp = strcmp(str1, str2);
            if (cmp == 0)
                printf("Strings are equal");
            else
                printf("Strings are not equal");
            break;
        case 4:
            strcat(str1, str2);
            printf("String concatenated successfully");
            break;
        case 5:
            strupr(str1);
            printf("String converted to upper case");
            break;
        case 6:
            strlwr(str1);
            printf("String converted to lower case");
            break;
        case 7:
            printf("String 1: %s \t String 2: %s", str1, str2);
            break;        
        case 8:
            return 0;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
