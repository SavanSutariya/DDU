#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

// Function to print the list
void printList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the list
void insertNodeAtBegin(Node** headRef, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *headRef;

    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }

    *headRef = newNode;
}

// Function to insert a node at the end of the list
void insertNodeAtEnd(Node** headRef, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        newNode->prev = NULL;
        *headRef = newNode;
        return;
    }

    Node* currNode = *headRef;

    while (currNode->next != NULL) {
        currNode = currNode->next;
    }

    currNode->next = newNode;
    newNode->prev = currNode;
}

// Function to insert a node before a given node
void insertNodeBefore(Node** headRef, int data, int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    if (*headRef == NULL) {
        printf("List is empty\n");
        free(newNode);
        return;
    }

    if ((*headRef)->data == key) {
        newNode->prev = NULL;
        newNode->next = *headRef;
        (*headRef)->prev = newNode;
        *headRef = newNode;
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

    newNode->prev = currNode->prev;
    newNode->next = currNode;
    currNode->prev->next = newNode;
    currNode->prev = newNode;
}

// Function to insert a node after a given node
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

    newNode->prev = currNode;
    newNode->next = currNode->next;

    if (currNode->next != NULL) {
        currNode->next->prev = newNode;
    }

    currNode->next = newNode;
}

void deleteNodeAtBegin(Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* currNode = *headRef;
    *headRef = currNode->next;

    if (currNode->next != NULL) {
        currNode->next->prev = NULL;
    }

    free(currNode);
}


// Function to delete the first node of the list
void deleteNodeAtEnd(Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* currNode = *headRef;

if (currNode->next == NULL) {
    *headRef = NULL;
    free(currNode);
    return;
}

while (currNode->next != NULL) {
    currNode = currNode->next;
}

currNode->prev->next = NULL;
free(currNode);
}

void deleteNode(Node** headRef, int key) {
if (*headRef == NULL) {
printf("List is empty\n");
return;
}

Node* currNode = *headRef;

if (currNode->data == key) {
    *headRef = currNode->next;
    if (currNode->next != NULL) {
        currNode->next->prev = NULL;
    }
    free(currNode);
    return;
}

while (currNode != NULL && currNode->data != key) {
    currNode = currNode->next;
}

if (currNode == NULL) {
    printf("%d not found in list\n", key);
    return;
}

currNode->prev->next = currNode->next;

if (currNode->next != NULL) {
    currNode->next->prev = currNode->prev;
}

free(currNode);
}

int main() {
Node* head = NULL;

insertNodeAtBegin(&head, 10);
insertNodeAtEnd(&head, 20);
insertNodeBefore(&head, 30, 20);
insertNodeAfter(&head, 40, 20);
deleteNodeAtBegin(&head);
deleteNodeAtEnd(&head);
deleteNode(&head, 30);

printList(head);

return 0;
}