#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next != *head) {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = *head;
}

void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* curr = *head;
    Node* prev = NULL;
    while (curr->next != *head) {
        if (curr->data == data) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr->data != data) {
        printf("Node not found\n");
        return;
    }
    if (curr == *head && curr->next == *head) {
        *head = NULL;
        free(curr);
        return;
    }
    if (curr == *head) {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = curr->next;
        last->next = *head;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* curr = head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    deleteNode(&head, 5);
    printList(head);
    deleteNode(&head, 1);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    deleteNode(&head, 4);
    printList(head);
    return 0;
}
