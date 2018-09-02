#include <bits/stdc++.h>
using namespace std;
  
struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
};

struct treenode* newtreenode(int n){
    struct treenode* newn = (struct treenode*) malloc(sizeof(struct treenode));
    newn->data = n;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
}

int height(treenode *root){
    if(!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root -> right);
    return (lh>rh)?lh+1:rh+1;
}

void inOrder(treenode *root){
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void mirror(treenode *root){
    if(!root)
        return;
    mirror(root->left);
    mirror(root->right);
    treenode *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main(){
  struct treenode *root = newtreenode(1);
  root->left        = newtreenode(2);
  root->right       = newtreenode(3);
  root->left->left  = newtreenode(4);
  root->left->right = newtreenode(5); 
   
  /* Print inorder traversal of the input tree
                1                 1
               / \               / \
              2   3     =>      3   2
             / \                   / \
            4   5                 5   4

  */
  printf("Inorder traversal of the constructed"
           " tree is \n");
  inOrder(root);
   
  /* Convert tree to its mirror */
  mirror(root); 
   
  /* Print inorder traversal of the mirror tree */
  printf("\nInorder traversal of the mirror tree"
         " is \n");  
  inOrder(root);
   
  return 0;  
}