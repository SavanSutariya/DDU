#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void inorder(struct node* root){
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(struct node* root){
    if(root==NULL)
        return;
    
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
struct node * createnewNode(int val){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}
struct node* insleft(struct node* root,int val){
    root->left=createnewNode(val);
    return root->left;
}
struct node* insright(struct node* root,int val){
    root->right=createnewNode(val);
    return root->right;
}

int main(){

  struct node* root=createnewNode(1);

  insleft(root, 12);
  insright(root, 9);

  insleft(root->left, 5);
  insright(root->left, 6);

  printf("Inorder traversal \n");
  inorder(root);

  printf("\nPreorder traversal \n");
  preorder(root);

  printf("\nPostorder traversal \n");
  postorder(root);
  return 0;
}