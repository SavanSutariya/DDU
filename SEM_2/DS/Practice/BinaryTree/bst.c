#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}node;

node *create(int val){
    node *n = (node *)malloc(sizeof(node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
}

node *insert(node *root, int val){
    if(root == NULL){
        return create(val);
    }
    if(val<root->val){
        root->left = insert(root->left,val);
    }
    else if(val>root->val){
        root->right = insert(root->right,val);
    }
    return root;
}
void inOrder(node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->val);
        inOrder(root->right);
    }
}
node *search(node *root, int val){
    if(root == NULL || root->val == val){
        return root;
    }
    if(val > root->val){
        return search(root->right,val);
    }
    else{
        return search(root->left,val);        
    }
}
int main(){
    node *tree = NULL;
    tree = insert(tree,9);
    insert(tree,4);
    insert(tree,11);
    insert(tree,2);
    insert(tree,7);
    insert(tree,15);
    insert(tree,5);
    insert(tree,8);
    insert(tree,14);
    printf("\n");
    inOrder(tree);
    printf("\n");
    if(search(tree,5) != NULL)
        printf("Searched : %d ",search(tree,14)->val);
    else
        printf("Not found");

    return 0;
}