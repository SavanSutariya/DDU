#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}node;
node *CreateNode(int val){
    node *n = (node *)malloc(sizeof(node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrder(node *root){
    if(root!=NULL){
        printf("%d ",root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->val);
    }
}
void inOrder(node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->val);
        inOrder(root->right);
    }
}
int main(){
    // Sample Tree
    //     4
    //    / \
    //   1   6
    //  / \ 
    // 5   2
    node *tree = CreateNode(4);
    tree->left = CreateNode(1);
    tree->right = CreateNode(6);
    tree->left->left = CreateNode(5);
    tree->left->right = CreateNode(2);
    preOrder(tree);
    printf("\n");
    postOrder(tree);
    printf("\n");
    inOrder(tree);
    // printf("%d",tree->left->left->val);
    return 0;
}