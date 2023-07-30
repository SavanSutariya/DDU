/*
(1)  Insert a Node in to BST
(2)  Search a Key in to BST
(3)  Smallest and Largest Element in BST
(4)  Preorder Traversal with Recursion and Without Recursion
(5)  Inorder Traversal with Recursion and Without Recursion
(6)  Postorder Traversal with Recursion and Without Recursion
(7)  Level Order Traversal
(8)  Height of Binary Search Tree
(9)  Floor and Ceil Element in BST
(10)  Deletion a Key in to BST

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* create(int data) {
    Node* newNode = (Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//(1)  Insert a Node in to BST

Node* insertNode( Node* root, int data) {
    if (root == NULL) {
        return create(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

//(2)  Search a Key in to BST
 Node* searchNode( Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return searchNode(root->right, key);
    else
        return searchNode(root->left, key);
}

//(3)  Smallest and Largest Element in BST
int findSmallestElement( Node* root) {
    // base case
    if (root == NULL) {
        return -1;
    }

    // if the left child is NULL, then the current node is the smallest element
    if (root->left == NULL) {
        return root->data;
    }

    // otherwise, recursively search for the smallest element in the left subtree
    return findSmallestElement(root->left);
}

// function to find the largest element in the tree
int findLargestElement( Node* root) {
    // base case
    if (root == NULL) {
        return -1;
    }

    // if the right child is NULL, then the current node is the largest element
    if (root->right == NULL) {
        return root->data;
    }

    // otherwise, recursively search for the largest element in the right subtree
    return findLargestElement(root->right);
}

//(4)  Preorder Traversal with Recursion and Without Recursion
void preorderTraversal( Node* root) {
    if (root == NULL)
        return;

    printf("%d -> ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void iterativePreorder(Node* root){
    if(root==NULL)
        return;

    Node* stack[100];
    int top=-1;
    stack[++top]=root;

    while(top>=0){
        Node* root=stack[top--];
        printf("%d -> ",root->data);

        if(root->right)
            stack[++top]=root->right;
        if(root->left)
            stack[++top]=root->left;
    }
}

//(5)  Inorder Traversal with Recursion and Without Recursion
void inorderTraversal( Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}

void iterativeInorder(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* curr = root;

    while(curr != NULL || top >= 0) {
        if(curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        } else {
            curr = stack[top--];
            printf("%d -> ", curr->data);
            curr = curr->right;
        }
    }
}

//(6)  Postorder Traversal with Recursion and Without Recursion
void postorderTraversal( Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->data);
}

void iterativePostorder(Node* root) {
    if(root == NULL) {
        return;
    }

    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;

    while(top1 >= 0) {
        Node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if(curr->left) {
            stack1[++top1] = curr->left;
        }
        if(curr->right) {
            stack1[++top1] = curr->right;
        }
    }

    while(top2 >= 0) {
        Node* curr = stack2[top2--];
        printf("%d -> ", curr->data);
    }
}

//(7)  Level Order Traversal
void levelorderTraversal( Node* root) {
    if (root == NULL) 
        return;

     Node** queue = ( Node**)malloc(sizeof( Node*) * 100);
    
    int front = -1;
    int rear = -1;

    queue[++rear] = root;
    
    while (front < rear) {
         Node* node = queue[++front];
        printf("%d ", node->data);
            if (node->left != NULL)
                queue[++rear] = node->left;
            if (node->right != NULL)
                queue[++rear] = node->right;
    }
}

//(8) Height of Binary Tree
int HeightofTree(Node* root){
    if(root==NULL)
        return 0;

    int left=HeightofTree(root->left);
    int right=HeightofTree(root->right);

    if(left>right)
        return left+1;
    else
        return right+1;
}

//(9)  Floor and Ceil Element in BST
int ceil(Node* root, int key) {
    int ceil = -1;

    while (root) {
        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }

        if (root->data < key) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }
    
    return ceil;
}

int floor(Node* root, int key) {
    int floor = -1;

    while (root) {
        if (root->data == key) {
            floor = root->data;
            return floor;
        }

        if (root->data > key) {
            root = root->left;
        } else {
            floor = root->data;
            root = root->right;
        }
    }
    
    return floor;
}


//(10) Deletion of Perticular key
 Node* minValueNode( Node* root)
{
     Node* current = root;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
 Node* deleteNode( Node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
             Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
             Node* temp = root->left;
            free(root);
            return temp;
        }
 
         Node* temp = minValueNode(root->right);
 
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main(){
    int data;
     Node* root=NULL;
    root = insertNode(root,25);
    insertNode(root,10);
    insertNode(root,100);
    insertNode(root,32);
    insertNode(root,22);
    insertNode(root,230);

    int key=220;
    if (searchNode(root, key) != NULL)
        printf("Element found in the tree.\n");
    else
        printf("Element not found in the tree.");

    printf("\n------------------------------------------------------\n");
    printf("Smallest element of the BST : %d\n",findSmallestElement(root));
    printf("Largest Element of the BST : %d",findLargestElement(root));
    printf("\n------------------------------------------------------\n");

    printf("Preorder Traversal : ");
    preorderTraversal(root);
    printf("\niterative : ");
    iterativePreorder(root);

    printf("\n------------------------------------------------------\n");

    printf("Inorder traversal : ");
    inorderTraversal(root);
    printf("\niterative : ");
    iterativeInorder(root);

    printf("\n------------------------------------------------------\n");

    printf("Postorder Traversal : ");
    postorderTraversal(root);
    printf("\niterative : ");
    iterativePostorder(root); 

    printf("\n------------------------------------------------------\n");

    printf("Level order traversal : ");
    levelorderTraversal(root);

    printf("\n------------------------------------------------------\n");
    printf("Height of Binary Tree : ");
    printf("%d ",HeightofTree(root));
    
    printf("\n------------------------------------------------------\n");
    printf(" Celi of Binary search tree is : %d\n",ceil(root,32));
    printf("Floor of Binary Search tree is : %d",floor(root,22));

    printf("\n------------------------------------------------------\n");
    int key1=100;
    root = deleteNode(root, key1);
    printf("Inorder traversal of the modified tree : ");
    inorderTraversal(root);
    printf("\n------------------------------------------------------\n");

    return 0;
}