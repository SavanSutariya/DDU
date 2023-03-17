#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

void printList(Node* head){
	if(head==NULL){
		printf("Linkedlist is empty\n");
	}else{
		Node* temp=head;
		while(temp!=NULL){
			printf("%d ->",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void insertNodeAtEnd(Node** head,int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;

	if(*head==NULL){
		*head=newNode;
		return;
	}else{
		Node* curr=*head;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=newNode;
	}
}

void insertNodeAtBegin(Node** head,int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=*head;
	*head=newNode;
}

void deleteNodeAtBegin(Node** head){
	if(*head==NULL){
		printf("List is empty\n");
		return;
	}else{
		Node* curr=*head;
		*head=curr->next;
		free(curr);
		printf("Node has been deleteNodeAtBegin\n");
	}
}

int main(){
	Node* head=NULL;
	insertNodeAtEnd(&head,10);
	insertNodeAtEnd(&head,20);
	insertNodeAtEnd(&head,30);
	insertNodeAtEnd(&head,40);
	deleteNodeAtBegin(&head);
	printList(head);
	return 0;
}









//2. insertNodeBegin
//4. insertNodePosition
//5. deleteNodeBegin
//6. deleteNodeEnd
//7. deletePosition
//8. sortlist
//9. deleteList
//10. countNodes
//11. SearchList