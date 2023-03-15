//  Define a structure Book which has members that include book_name, author_name,
// price and pages. Create a structure pointer variable which collects book information
// from the user and prints the book information for book_name starting with ‘D’. Also
// create a function which displays all book information using pointers.

#include <stdio.h>

struct book
{
    char book_name[30];
    char book_auther[30];
    float price;
    int pages;
};

int main()
{
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    struct book b[n];
    struct book *ptr;
    ptr = b;
    printf("Enter Details\n");
    for (int i = 0; i < n; i++, ptr++)
    {
        printf("Enter book name: ");
        scanf("%s", ptr->book_name);
        printf("Enter book Auther Name: ");
        scanf("%s", ptr->book_auther);
        printf("Enter book Price: ");
        scanf("%f", &ptr->price);
        printf("Enter book Pages: ");
        scanf("%d", &ptr->pages);
    }
    printf("Book has start with d letter: ");
    ptr = b;
    for (int i = 0; i < n; i++, ptr++)
    {
        if (ptr->book_name[0] == 'd' || ptr->book_name[0] == 'D')
        {
            printf("book name is: %s\n", ptr->book_name);
            printf("book Auther Name is: %s\n", ptr->book_auther);
            printf("book Price is: %f\n", ptr->price);
            printf("book Pages are: %d\n", ptr->pages);
            printf("----------------------");
        }
    }
    return 0;
}