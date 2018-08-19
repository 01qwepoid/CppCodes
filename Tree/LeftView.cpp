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

void leftViewUtil(node *root, int level, int *max_level){
	if(!root)
		return;
	if(*max_level < level){
		cout<<root->data<<" ";
		*max_level = level;
	}
	leftViewUtil(root->left, level +1, max_level);
	leftViewUtil(root->right, level +1, max_level);
}

void leftView(node *root){
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}

int main(){
    struct node *root = newnode(12);
    root->left = newnode(10);
    root->right = newnode(30);
    root->right->left = newnode(25);
    root->right->right = newnode(40);
 
    leftView(root);
 
    return 0;
}