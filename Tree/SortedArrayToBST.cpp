#include <bits/stdc++.h>
using namespace std;
  
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node *newnode(int n){
    struct node *newn = (struct node*) malloc(sizeof(struct node));
    newn ->data = n;
    newn ->left = NULL;
    newn->right = NULL;
    return newn;
}

struct node* arraytobst(int a[], int start, int end){
    if(start>end)
        return NULL;
    int mid = (start+end)/2;
    struct node* root = newnode(a[mid]);
    root->left = arraytobst(a, start, mid-1);
    root->right = arraytobst(a, mid+1, end);
    return root;
}
 
void preorder(struct node* root){
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
} 
 
int main() {
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/ sizeof(a[0]);
    struct node* root = arraytobst(a, 0 ,n-1);
    preorder(root);
    return 0;
}