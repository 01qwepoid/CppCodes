#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}
 
int height(node *root){
    if(!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh>rh)
        return (1+lh);
    return 1 + rh;
}

bool identicalTrees(node* a, node *b){
	if(!a && !b)
		return 1;
	if(a && b){
		return (a->data == b->data &&
		 identicalTrees(a->left, b->left) &&
		 identicalTrees(a->right, b->right));
	}
	return 0;
}

int main(){
    struct node *root1 = newNode(1);
    struct node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 
    cout<<height(root1);
  return 0;
}