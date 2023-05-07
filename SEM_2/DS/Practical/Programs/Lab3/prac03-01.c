#include<stdio.h>
struct book{
    char book_name[20];
    char author_name[20];
    float price;
    int pages;
};
void read_book_values(struct book *b){
    printf("\nEnter book name:");
    scanf(" %[^\n]s",b->book_name);
    printf("\nEnter Author name:");
    scanf(" %[^\n]s",b->author_name);
    printf("\nEnter Price:");
    scanf("%f",&b->price);
    printf("\nEnter Pages:");
    scanf("%d",&b->pages);
}
void print_book(struct book *b){
    printf("\nBook Info\n");
    printf("\nName : %s",b->book_name);
    printf("\nAuthor : %s",b->author_name);
    printf("\nPrice : %.2f",b->price);
    printf("\nPages : %d",b->pages);
}
void print_starts_with(struct book b[],int n,char c){
    for(int i=0; i<n; i++){
        if(b[i].book_name[0] == c){
            print_book(&b[i]);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    struct book b[n];
    for(int i=0; i<n; i++){
        read_book_values(&b[i]);
    }
    print_starts_with(b,n,'D');
    return 0;
}