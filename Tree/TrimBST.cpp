#include<bits/stdc++.h>
using namespace std;
 
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* newNode(int num){
    node* newn = (struct node*) malloc(sizeof(struct node));
    newn->data = num;
    newn->left=NULL;
    newn->right = NULL;
    return newn;
}
 
node* insert(node* root, int key){
    if (root == NULL)
       return newNode(key);
    if (root->data > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}
 
node* trimtree(node* root, int min, int max){
    if(!root)
        return NULL;
    root->left = trimtree(root->left, min,max);
    root->right = trimtree(root->right, min,max);
    if(root->data <min){
        node *rchild = root->right;
        delete root;
        return rchild;
    }
    if(root->data > max){
        node*lchild = root->left;
        delete root;
        return lchild;
    }
    return root;
} 


void inorderTraversal(node* root){
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}
 
int main(){
    node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
 
    cout << "Inorder traversal of the given tree is: ";
    inorderTraversal(root);
 
    root = trimtree(root, -10, 13);
 
    cout << "\nInorder traversal of the modified tree is: ";
    inorderTraversal(root);
 
    return 0;
}