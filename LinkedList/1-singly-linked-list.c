#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void printList(Node* head) {
    if(head==NULL){
        printf("Linkedlist is empty\n");
    }

    Node* temp=head;
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}


void insertNodeAtBegin(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertNodeAtEnd(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    //it not any node exits
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* currNode = *head;

    while (currNode->next != NULL) {
        currNode = currNode->next;
    }

    currNode->next = newNode;
}

void insertNodePosition( Node** headRef, int data, int position) {
     Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = data;

    Node* currNode = *headRef;
     Node* prevNode = NULL; 
    if (position == 1) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }
    else{
     for (int i = 1; i < position && currNode != NULL; i++) {
        prevNode = currNode;
        currNode = currNode->next;
    }
   }

    if (currNode == NULL && position > 1) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }else{
        newNode->next = currNode;
        prevNode->next = newNode;
    }
}

void deleteNodeAtBegin(Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* currNode = *headRef;
    *headRef = currNode->next;
    free(currNode);
    printf("First node deleted from list\n");
}

void deleteNodeAtEnd(Node** headRef) {
    //1. list is empty
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }

    //2. only one node present
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        printf("Last node deleted from list\n");
        return;
    }
    //two or more node are present
    else{
        Node* currNode = *headRef;
        Node* prevNode = NULL;

        while (currNode->next != NULL) {
            prevNode = currNode;
            currNode = currNode->next;
        }

      prevNode->next = NULL;
      free(currNode);
      printf("Last node deleted from list\n");
    }
}

void deleteNodeAtPosition(Node** headRef, int position) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* currNode = *headRef;
    Node* prevNode = NULL;
    int currPos = 0;

    while (currNode != NULL && currPos != position) {
        prevNode = currNode;
        currNode = currNode->next;
        currPos++;
    }

    if (currNode == NULL) {
        printf("Position %d not found in list\n", position);
        return;
    }

    if (prevNode == NULL) {
        *headRef = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    free(currNode);
    printf("Node at position %d deleted from list\n", position);
}

void deleteList(Node** headRef) {
    Node* currNode = *headRef;

    while (currNode != NULL) {
        Node* nodeToDelete = currNode;
        currNode = currNode->next;
        free(nodeToDelete);
    }

    *headRef = NULL;
    printf("List deleted\n");
}

void sortList(Node** headRef) {
    Node* currNode = *headRef;

    while (currNode != NULL) {
        Node* nodeToCompare = currNode->next;

        while (nodeToCompare != NULL) {
            if (currNode->data > nodeToCompare->data) {
                int temp = currNode->data;
                currNode->data = nodeToCompare->data;
                nodeToCompare->data = temp;
            }

            nodeToCompare = nodeToCompare->next;
        }

        currNode = currNode->next;
    }

    printf("List sorted in ascending order\n");
}

int countNodes(Node** head) {
    int count = 0;
    Node* current = *head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

Node* searchList(Node** head, int search) {
    Node* currNode = *head;
    while (currNode != NULL && currNode->data != search) {
        currNode = currNode->next;
    }
    return currNode;
}


// Node* copyList(Node* head) {
//     if (head == NULL) {
//         return NULL;
//     }

//     Node* newHead = (Node*) malloc(sizeof(Node));
//     newHead->data = head->data;
//     newHead->next = NULL;

//     Node* currNode = head->next;
//     Node* prevNode = newHead;

//     while (currNode != NULL) {
//         Node* newNode = (Node*) malloc(sizeof(Node));
//         newNode->data = currNode->data;
//         newNode->next = NULL;

//         prevNode->next = newNode;
//         prevNode = newNode;
//         currNode = currNode->next;
//     }

//     return newHead;
// }

int main() {
    Node* head = NULL;
    int choice, data, key,search,position;

    while (1) {
        printf("Enter your choice:\n");
        printf("0. Print LinkedList : \n");
        printf("1. Insert node at beginning\n");
        printf("2. Insert node at end\n");
        printf("3. Insert node Perticular position \n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Delete node Perticular Position \n");
        printf("7. Delete entire list\n");
        printf("8. Sort list\n");
        printf("9. Count Node : \n");
        printf("10. Search Node :\n");
        printf("11. Exit\n");
        printf("12. Clear the Screen \n");

        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printList(head);
                break;
            case 1:
                printf("Enter data to insert at beginning:\n");
                scanf("%d", &data);
                insertNodeAtBegin(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end:\n");
                scanf("%d", &data);
                insertNodeAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert:\n");
                scanf("%d", &data);
                printf("Enter position to want add node :\n");
                scanf("%d", &position);
                insertNodePosition(&head, data, position);
                break;
            case 4:
                deleteNodeAtBegin(&head);
                break;
            case 5:
                deleteNodeAtEnd(&head);
                break;
            case 6:
                printf("Enter the position to delete:\n");
                scanf("%d", &position);
                deleteNodeAtPosition(&head, position);
                break;
            case 7:
                deleteList(&head);
                break;
            case 8:
                sortList(&head);
                break;
            case 9:
                printf("In this Linkedlist Total node is : \n");
                printf("%d\n", countNodes(&head));
                break;
            case 10:
                printf("Enter the Searching Node \n");
                scanf("%d",&search);
                searchList(&head,search);
                break;
            case 11:
                printf("Exiting program\n");
                exit(0);
            case 12:
                printf("Clear the Screen\n");
                system("clear");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
            // case 10:
            //     printf("Enter the searching value here : \n");
            //     scanf("%d",&search);
            //     searchList(head,search);
            //     break;
            
        }
    }

    return 0;
}

