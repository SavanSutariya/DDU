/*
(1)  Preorder Traversal with Recursion and Without Recursion
(2)  Inorder Traversal with Recursion and Without Recursion
(3)  Postorder Traversal with Recursion and Without Recursion
(4)  Level Order Traversal
(5)  Height of Binary Tree
(6)  Check if Tree is Balanced or not
(7)  Diameter of Binary Tree
(8)  Check if tree is Mirror or not
(9)  Construct A Binary Tree from Inorder and Preorder Traversal
(10) Construct Binary Tree from Inorder and PostOrder Traversal
(11) Count node in to Binary Tree
(12) Internal and External Node in to Binary tree
(13) Diameter of Binary Tree

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
}

//(1) Preorder Traversal with Recursion and Without Recursion
void preorderTraversal(Node* root){
    if(root==NULL)
        return;
    printf("%d -> ",root->data);
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

//(2) Inorder Traversal with Recursion and Without Recursion

void inorderTraversal(Node* root){
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    printf("%d -> ",root->data);
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

//(3) Postorder Traversal with Recursion and Without Recursion
void postorderTraversal(Node* root){
    if(root==NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ",root->data);

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

//(4) Level Order Traversal
struct Queue {
     Node* data;
     Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

void enqueue( Node* x) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue() {
    struct Queue* temp = front;
    if (front == NULL) {
        return;
    }
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}

void level_order_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    enqueue(root);
    while (front != NULL) {
        Node* current = front->data;
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(current->left);
        }
        if (current->right != NULL) {
            enqueue(current->right);
        }
        dequeue();
    }
}

//(5) Height of Binary Tree
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

//(6) Check if Tree is Balanced or not
int dfsHeight( Node* root) {
    if (root == NULL) 
        return 0;

    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1) 
        return -1;

    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1) 
        return -1;

    if (abs(leftHeight - rightHeight) > 1)  
        return -1;

    if(leftHeight > rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;
}

bool isBalanced( Node* root) {
    return dfsHeight(root) != -1;
}

//(7) Diameter of Binary Tree
//->Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.

int max(int a,int b){
    return a > b ? a : b;
}
int HeightofTreeD(Node* root,int &diameter){
    if(root==NULL)
        return 0;

    int left=HeightofTreeD(root->left,diameter);
    int right=HeightofTreeD(root->right,diameter);

    
    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(Node* root) {
        int diameter = 0;
        HeightofTreeD(root, diameter);
        return diameter;
}

//(8) Check if tree is Mirror or not
// for better understanding : https://takeuforward.org/data-structure/check-for-symmetrical-binary-tree/

bool isSymmetricUtil(Node * root1, Node * root2) {
  if (root1 == NULL || root2 == NULL)
    return root1 == root2;
  return (root1 -> data == root2 -> data) && isSymmetricUtil(root1 -> left, root2->
  right) && isSymmetricUtil(root1 -> right, root2 -> left);
}

bool isSymmetric(Node * root) {
  if (!root) 
    return true;
  return isSymmetricUtil(root -> left, root -> right);
}

//(9) Construct A Binary Tree from Inorder and Preorder Traversal
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

Node* newTree(int *preorder, int *inorder, int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd)
        return NULL;
    
    Node *root = (Node*)malloc(sizeof(Node));
    root->data = preorder[*preIndex];
    (*preIndex)++;
    if (inStart == inEnd) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    int inIndex = search(inorder, inStart, inEnd, root->data);
    root->left = newTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = newTree(preorder, inorder, inIndex + 1, inEnd, preIndex);
    return root;
}

Node* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return newTree(preorder, inorder, 0, inorderSize - 1, &preIndex);
}

//(10) Construct Binary Tree from Inorder and PostOrder Traversal
 Node* newTreeINTOPOST(int *inordernew, int *postordernew, int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }
    Node *root = ( Node*)malloc(sizeof( Node));
    root->data = postordernew[*postIndex];
    (*postIndex)--;
    if (inStart == inEnd) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    int inIndex = search(inordernew, inStart, inEnd, root->data);
    root->right = newTreeINTOPOST(inordernew, postordernew, inIndex + 1, inEnd, postIndex);
    root->left = newTreeINTOPOST(inordernew, postordernew, inStart, inIndex - 1, postIndex);
    return root;
}

Node* newBuildINTOPOST(int* inordernew, int inorderSize, int* postordernew, int postorderSize) {
    int postIndex = postorderSize - 1;
    return newTreeINTOPOST(inordernew, postordernew, 0, inorderSize - 1, &postIndex);
}

//(11) Count node in to Binary Tree
int countNodes(Node* root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

//(12) Internal and External Node  in to Binary tree
//-> In a binary tree, a node is said to be an internal node if it has at least one child (i.e., a left child or a right child or both), and it is said to be an external node (also known as a leaf node) if it has no children.
void countNodesINTEXTER(Node* root, int* internal, int* external)
{
    if (root == NULL)
        return;
    else if (root->left == NULL && root->right == NULL)
        (*external)++;
    else {
        (*internal)++;
        countNodesINTEXTER(root->left, internal, external);
        countNodesINTEXTER(root->right, internal, external);
    }
}

//(13) Diameter of Binary Tree
int diameter( Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);
    int root_path = HeightofTree(root->left) + HeightofTree(root->right) + 1;
    int max_diameter;
    if (left_diameter > right_diameter) {
        max_diameter = left_diameter;
    } else {
        max_diameter = right_diameter;
    }
    if (root_path > max_diameter) {
        return root_path;
    } else {
        return max_diameter;
    }
}
int main(){
    Node* root=create(10);
    root->left=create(20);
    root->right=create(60);
    root->left->left=create(90);
    root->left->right=create(110);
    root->right->left=create(125);
    root->right->right=create(200);
    root->right->right->left=create(2001);
    root->right->right->left->right=create(21001);

    printf("recursive preorder : ");
    preorderTraversal(root);
    printf("\niterative : ");
    iterativePreorder(root);

    printf("\n------------------------------------------------------\n");

    printf("recursive inorder : ");
    inorderTraversal(root);
    printf("\niterative : ");
    iterativeInorder(root);

    printf("\n------------------------------------------------------\n");

    printf("recursive postoder : ");
    postorderTraversal(root);
    printf("\niterative : ");
    iterativePostorder(root);    

    printf("\n------------------------------------------------------\n");
    printf("Level order traversal of binary tree: ");
    level_order_traversal(root);

    printf("\n------------------------------------------------------\n");
    printf("Height of Binary Tree : ");
    printf("%d ",HeightofTree(root));

    printf("\n------------------------------------------------------\n");
    if(isBalanced(root)){
        printf("is isBalanced\n");
    }else{
        printf("it not isBalanced");
    }

    printf("\n------------------------------------------------------\n");
    printf("diameter of Binary Tree : ");
    printf("%d ",diameterOfBinaryTree(root));

    printf("\n------------------------------------------------------\n");

    if (isSymmetric(root))
        printf("The tree is Mirror");
    else 
        printf("The tree is NOT Mirror");

    printf("\n------------------------------------------------------\n");

    int preorder[] = {10,20,40,50,30,60};
    int inorder[] = {40,20,50,10,60,30};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    Node *root1 = buildTree(preorder, n, inorder, n);

    buildTree(preorder, n, inorder, n);
    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root1);

    printf("\n------------------------------------------------------\n");

    int inordernew[] = {40,20,50,10,60,30};
    int postordernew[] = {40,50,20,60,30,10};
    int n1 = sizeof(inordernew) / sizeof(inordernew[0]);
    Node *root2 = buildTree(inordernew, n1, postordernew, n1);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root2);

    printf("\n------------------------------------------------------\n");
    printf("Count the total nodes in to Binary Tree : ");
    printf("%d ",countNodes(root));

    printf("\n------------------------------------------------------\n");
    int internal = 0, external = 0;
    countNodesINTEXTER(root, &internal, &external);
    printf("The number of internal nodes in the binary tree is: %d\n", internal);
    printf("The number of external nodes in the binary tree is: %d\n", external);

    printf("\n------------------------------------------------------\n");
    printf("Diameter of Binary Tree is : ");
    printf("%d ",diameter(root));
    return 0;
}