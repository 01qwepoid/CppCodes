#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left, *right;
};

struct node* newnode(int data){
    struct node* newn = new node;
    newn->data = data;
    newn->left = newn->right = NULL;
    return newn;    
}

void rightViewUtil(node *root, int level, int *max_level){
    if(!root)
        return;
    if(*max_level < level){
        cout<<root->data<<" ";
        *max_level = level;
    }
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}

void rightView(node *root){
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

int main(){
    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
 
    rightView(root);
}