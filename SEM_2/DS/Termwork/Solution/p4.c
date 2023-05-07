#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct contact{
    int cust_id;
    char name[20];
    char phone_number[13];
    struct contact *next;
}contact;

typedef struct directory{
    contact *head;
}directory;

contact *createContact(int cust_id,char name[],char phone_number[]){
    contact *new = (contact *)malloc(sizeof(contact));
    new->cust_id = cust_id;
    strcpy(new->name,name);
    strcpy(new->phone_number,phone_number);
    new->next = NULL;
    return new;
}
// Check if already exists
int exists(directory *d,int cust_id){
    if(d->head == NULL){
        return 0;
    }
    contact *tmp = d->head;
    while(tmp->next != d->head){
        if(tmp->cust_id == cust_id){
            return 1;
        }
        tmp = tmp->next;
    }
    if(tmp->cust_id == cust_id){
        return 1;
    }
    return 0;
}
// insert at first
void insertAtFirst(directory *d,int cust_id,char name[],char phone_number[]){
    if(exists(d,cust_id)){
        printf("Already exists");
        return;
    }
    contact *new = createContact(cust_id,name,phone_number);
    if(d->head == NULL){
        d->head = new;
        new->next = new;
        return;
    }
    contact *tmp = d->head;
    while(tmp->next != d->head){
        tmp = tmp->next;
    }
    tmp->next = new;
    new->next = d->head;
    d->head = new;
}
// insert at last
void insertAtLast(directory *d,int cust_id,char name[],char phone_number[]){
    if(exists(d,cust_id)){
        printf("Already exists");
        return;
    }
    contact *new = createContact(cust_id,name,phone_number);
    if(d->head == NULL){
        d->head = new;
        new->next = new;
        return;
    }
    contact *tmp = d->head;
    while(tmp->next != d->head){
        tmp = tmp->next;
    }
    tmp->next = new;
    new->next = d->head;
}
// insert in order of cust_id
void insertInOrder(directory *d,int cust_id,char name[],char phone_number[]){

    contact *new = createContact(cust_id,name,phone_number);
    if(d->head == NULL){
        d->head = new;
        new->next = new;
        return;
    }
    contact *tmp = d->head;
    if(tmp->cust_id > cust_id){
        while(tmp->next != d->head){
            tmp = tmp->next;
        }
        tmp->next = new;
        new->next = d->head;
        d->head = new;
        return;
    }
    while(tmp->next != d->head && tmp->next->cust_id < cust_id){
        tmp = tmp->next;
    }
    new->next = tmp->next;
    tmp->next = new;
}
// delete first
void deleteFirst(directory *d){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    contact *tmp = d->head;
    while(tmp->next != d->head){
        tmp = tmp->next;
    }
    tmp->next = d->head->next;
    tmp = d->head;
    d->head = d->head->next;
    free(tmp);
}
// delete last
void deleteLast(directory *d){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    contact *tmp = d->head;
    while(tmp->next->next != d->head){
        tmp = tmp->next;
    }
    contact *tmp2 = tmp->next;
    tmp->next = d->head;
    free(tmp2);
}
// delete from specific
void deleteFromSpecific(directory *d,int cust_id){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    contact *tmp = d->head;
    if(tmp->cust_id == cust_id){
        while(tmp->next != d->head){
            tmp = tmp->next;
        }
        tmp->next = d->head->next;
        tmp = d->head;
        d->head = d->head->next;
        free(tmp);
        return;
    }
    while(tmp->next != d->head && tmp->next->cust_id != cust_id){
        tmp = tmp->next;
    }
    if(tmp->next == d->head){
        printf("Not found");
        return;
    }
    contact *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}

// Search by name -----------------------------------------
void searchByName(directory *d,char name[]){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    contact *tmp = d->head;
    while(tmp->next != d->head){
        if(strcmp(tmp->name,name) == 0){
            printf("Found\n");
            printf("Customer ID: %d\n",tmp->cust_id);
            printf("Name: %s\n",tmp->name);
            printf("Phone Number: %s\n",tmp->phone_number);
            return;
        }
        tmp = tmp->next;
    }
    if(strcmp(tmp->name,name) == 0){
        printf("Found\n");
        printf("Customer ID: %d\n",tmp->cust_id);
        printf("Name: %s\n",tmp->name);
        printf("Phone Number: %s\n",tmp->phone_number);
        return;
    }
    printf("Not found");
}

// Search by cust_id -----------------------------------------
void searchByCustId(directory *d,int cust_id){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    contact *tmp = d->head;
    while(tmp->next != d->head){
        if(tmp->cust_id == cust_id){
            printf("Found\n");
            printf("Customer ID: %d\n",tmp->cust_id);
            printf("Name: %s\n",tmp->name);
            printf("Phone Number: %s\n",tmp->phone_number);
            return;
        }
        tmp = tmp->next;
    }
    if(tmp->cust_id == cust_id){
        printf("Found\n");
        printf("Customer ID: %d\n",tmp->cust_id);
        printf("Name: %s\n",tmp->name);
        printf("Phone Number: %s\n",tmp->phone_number);
        return;
    }
    printf("Not found");
}

// Search by phone number -----------------------------------------
void searchByPhoneNumber(directory *d,char phone_number[]){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    contact *tmp = d->head;
    while(tmp->next != d->head){
        if(strcmp(tmp->phone_number,phone_number) == 0){
            printf("Found\n");
            printf("Customer ID: %d\n",tmp->cust_id);
            printf("Name: %s\n",tmp->name);
            printf("Phone Number: %s\n",tmp->phone_number);
            return;
        }
        tmp = tmp->next;
    }
    if(strcmp(tmp->phone_number,phone_number) == 0){
        printf("Found\n");
        printf("Customer ID: %d\n",tmp->cust_id);
        printf("Name: %s\n",tmp->name);
        printf("Phone Number: %s\n",tmp->phone_number);
        return;
    }
    printf("Not found");
}

// delete by name
void deleteByName(directory *d,char name[]){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    contact *tmp = d->head;
    if(strcmp(tmp->name,name) == 0){
        while(tmp->next != d->head){
            tmp = tmp->next;
        }
        tmp->next = d->head->next;
        tmp = d->head;
        d->head = d->head->next;
        free(tmp);
        return;
    }
    while(tmp->next != d->head && strcmp(tmp->next->name,name) != 0){
        tmp = tmp->next;
    }
    if(tmp->next == d->head){
        printf("Not found");
        return;
    }
    contact *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}

// delete by cust_id
void deleteByCustId(directory *d,int cust_id){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    contact *tmp = d->head;
    if(tmp->cust_id == cust_id){
        while(tmp->next != d->head){
            tmp = tmp->next;
        }
        tmp->next = d->head->next;
        tmp = d->head;
        d->head = d->head->next;
        free(tmp);
        return;
    }
    while(tmp->next != d->head && tmp->next->cust_id != cust_id){
        tmp = tmp->next;
    }
    if(tmp->next == d->head){
        printf("Not found");
        return;
    }
    contact *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}

// delete by phone number
void deleteByPhoneNumber(directory *d,char phone_number[]){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    contact *tmp = d->head;
    if(strcmp(tmp->phone_number,phone_number) == 0){
        while(tmp->next != d->head){
            tmp = tmp->next;
        }
        tmp->next = d->head->next;
        tmp = d->head;
        d->head = d->head->next;
        free(tmp);
        return;
    }
    while(tmp->next != d->head && strcmp(tmp->next->phone_number,phone_number) != 0){
        tmp = tmp->next;
    }
    if(tmp->next == d->head){
        printf("Not found");
        return;
    }
    contact *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}

// display
void display(directory *d){
    if(d->head == NULL){
        printf("Empty");
        return;
    }
    printf("\n--------------Directory--------------");
    contact *tmp = d->head;
    while(tmp->next != d->head){
        printf("\n%d",tmp->cust_id);
        printf(" %20s",tmp->name);
        printf(" %13s",tmp->phone_number);
        tmp = tmp->next;
    }
    printf("\n%d",tmp->cust_id);
    printf(" %20s",tmp->name);
    printf(" %13s",tmp->phone_number);
    printf("\n-------------------------------------");

}

// display sorted
void displaySorted(directory *d){
    // copy the list then sort that
    directory d1;
    d1.head = NULL;
    contact *tmp = d->head;
    while(tmp->next != d->head){
        insertInOrder(&d1,tmp->cust_id,tmp->name,tmp->phone_number);
        tmp = tmp->next;
    }
    insertInOrder(&d1,tmp->cust_id,tmp->name,tmp->phone_number);
    display(&d1);
}

int main(){
    // menu
    directory d;
    d.head = NULL;
    int id;
    char name[20];
    char phone_number[13];
    while(1){
        printf("\n1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Insert in sorted order\n");
        printf("4. Delete from first\n");
        printf("5. Delete from last\n");
        printf("6. Delete from specific position\n");
        printf("7. Display in sorted order\n");
        printf("8. Search by name\n");
        printf("9. Search by cust_id\n");
        printf("10. Search by phone_number\n");
        printf("11. Delete by name\n");
        printf("12. Delete by cust_id\n");
        printf("13. Delete by phone_number\n");
        printf("14. Display\n");
        printf("15. Exit\n");
        
        printf("Enter your choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter cust_id: ");
                scanf("%d",&id);
                printf("Enter name: ");
                scanf("%s",name);
                printf("Enter phone_number: ");
                scanf("%s",phone_number);
                insertAtFirst(&d,id,name,phone_number);
                break;
            case 2:
                printf("Enter cust_id: ");
                scanf("%d",&id);
                printf("Enter name: ");
                scanf("%s",name);
                printf("Enter phone_number: ");
                scanf("%s",phone_number);
                insertAtLast(&d,id,name,phone_number);
                break;
            case 3:
                printf("The sequence of directory may get changed");
                printf("Do you want to continue (y/n): ");
                char ch;
                scanf(" %c",&ch);
                if(ch == 'n')
                    break;
                printf("Enter cust_id: ");
                scanf("%d",&id);
                printf("Enter name: ");
                scanf("%s",name);
                printf("Enter phone_number: ");
                scanf("%s",phone_number);
                insertInOrder(&d,id,name,phone_number);
                break;
            case 4:
                deleteFirst(&d);
                break;
            case 5:
                deleteLast(&d);
                break;
            case 6:
                printf("Enter position: ");
                int pos;
                scanf("%d",&pos);
                deleteFromSpecific(&d,pos);
                break;
            case 7:
                displaySorted(&d);
                break;
            case 8:
                printf("Enter name: ");
                scanf("%s",name);
                searchByName(&d,name);
                break;
            case 9:
                printf("Enter cust_id: ");
                scanf("%d",&id);
                searchByCustId(&d,id);
                break;
            case 10:
                printf("Enter phone_number: ");
                scanf("%s",phone_number);
                searchByPhoneNumber(&d,phone_number);
                break;
            case 11:
                printf("Enter name: ");
                scanf("%s",name);
                deleteByName(&d,name);
                break;
            case 12:
                printf("Enter cust_id: ");
                scanf("%d",&id);
                deleteByCustId(&d,id);
                break;
            case 13:
                printf("Enter phone_number: ");
                scanf("%s",phone_number);
                deleteByPhoneNumber(&d,phone_number);
                break;
            case 14:
                display(&d);
                break;
            case 15:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}