#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void printList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertNodeAtBegin(Node** headRef, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertNodeAtEnd(Node** headRef, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* currNode = *headRef;

    while (currNode->next != NULL) {
        currNode = currNode->next;
    }

    currNode->next = newNode;
}

void insertNodeBefore(Node** headRef, int data, int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    if (*headRef == NULL) {
        printf("List is empty\n");
        free(newNode);
        return;
    }

    if ((*headRef)->data == key) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    Node* currNode = *headRef;
    Node* prevNode = NULL;

    while (currNode != NULL && currNode->data != key) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("%d not found in list\n", key);
        free(newNode);
        return;
    }

    newNode->next = currNode;
    prevNode->next = newNode;
}

void insertNodeAfter(Node** headRef, int data, int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    if (*headRef == NULL) {
        printf("List is empty\n");
        free(newNode);
        return;
    }

    Node* currNode = *headRef;

    while (currNode != NULL && currNode->data != key) {
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("%d not found in list\n", key);
        free(newNode);
        return;
    }

    newNode->next = currNode->next;
    currNode->next = newNode;
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
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        printf("Last node deleted from list\n");
        return;
    }

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

void deleteNodeBefore(Node** headRef, int key) {
    if (*headRef == NULL || (*headRef)->next == NULL) {
        printf("List is empty or has only one node\n");
        return;
    }

    if ((*headRef)->data == key) {
        printf("Key is the first node in the list, no node to delete before it\n");
        return;
    }

    Node* currNode = *headRef;
    Node* prevNode = NULL;
    Node* prevPrevNode = NULL;

    while (currNode != NULL && currNode->data != key) {
        prevPrevNode = prevNode;
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("%d not found in list\n", key);
        return;
    }

    if (prevPrevNode == NULL) {
        *headRef = currNode;
    } else {
        prevPrevNode->next = currNode;
    }

    free(prevNode);
    printf("Node before %d deleted from list\n", key);
}

void deleteNodeAfter(Node** headRef, int key) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* currNode = *headRef;

    while (currNode != NULL && currNode->data != key) {
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("%d not found in list\n", key);
        return;
    }

    if (currNode->next == NULL) {
        printf("Key is the last node in the list, no node to delete after it\n");
        return;
    }

    Node* nodeToDelete = currNode->next;
    currNode->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node after %d deleted from list\n", key);
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

int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* copyList(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* newHead = (Node*) malloc(sizeof(Node));
    newHead->data = head->data;
    newHead->next = NULL;

    Node* currNode = head->next;
    Node* prevNode = newHead;

    while (currNode != NULL) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = currNode->data;
        newNode->next = NULL;

        prevNode->next = newNode;
        prevNode = newNode;
        currNode = currNode->next;
    }

    return newHead;
}


int main() {
    Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert node at beginning\n");
        printf("2. Insert node at end\n");
        printf("3. Insert node before a key\n");
        printf("4. Insert node after a key\n");
        printf("5. Delete first node\n");
        printf("6. Delete last node\n");
        printf("7. Delete node before a key\n");
        printf("8. Delete node after a key\n");
        printf("9. Sort list\n");
        printf("10. Delete entire list\n");
        printf("11. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
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
                printf("Enter key before which to insert:\n");
                scanf("%d", &key);
                insertNodeBefore(&head, data, key);
                break;
            case 4:
                printf("Enter data to insert:\n");
                scanf("%d", &data);
                printf("Enter key after which to insert:\n");
                scanf("%d", &key);
                insertNodeAfter(&head, data, key);
                break;
            case 5:
                deleteNodeAtBegin(&head);
                break;
            case 6:
                deleteNodeAtEnd(&head);
                break;
            case 7:
                printf("Enter key before which to delete:\n");
                scanf("%d", &key);
                deleteNodeBefore(&head, key);
                break;
            case 8:
                printf("Enter key after which to delete:\n");
                scanf("%d", &key);
                deleteNodeAfter(&head, key);
                break;
            case 9:
                sortList(&head);
                break;
            case 10:
                deleteList(&head);
                break;
            case 11:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}

