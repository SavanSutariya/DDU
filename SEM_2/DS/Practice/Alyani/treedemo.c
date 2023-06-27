#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int data)
{
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}
struct node* insleft(struct node* root,int data){
    root->left=createNode(data);
    return root->left;
}
struct node* insright(struct node* root,int data)
{
    root->right=createNode(data);
    return root->right;
}
void inordeer(struct node* root)
{
    if(root==NULL)
        return;
    inordeer(root->left);
    printf("%d ",root->data);
    inordeer(root->right);
}
void preorder(struct node* root){
    if(root == NULL)
        return;
    printf("%d" ,root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->left);
    printf("%d ",root->data);
}
int main(){
    struct node* root=createNode(1);
    insleft(root->left,10);
    insleft(root->left,20);
    insleft(root->right,30);
    insleft(root->right,40);
    insleft(root->right,50);
    insleft(root->left,60);insleft(root->left,70);

    inordeer(root);

    return 0;
}