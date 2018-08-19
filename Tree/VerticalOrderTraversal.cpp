#include<bits/stdc++.h>
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

void getverticalorder(node *root, int hd, map<int, vector<int>> &m){
    if(!root)
        return;
    m[hd].push_back(root->data);
    getverticalorder(root->left, hd-1, m);
    getverticalorder(root->right, hd+1, m);
}

void printVerticalOrder(node *root){
    map<int, vector<int>> m;
    int hd =0;
    getverticalorder(root,hd,m);
    
    auto it = m.begin();
    for(;it!=m.end();it++){
        for(int i=0;i<it->second.size();i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
}

int main(){
    node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
    root->right->right->right = newnode(9);
    cout << "Vertical order traversal is n"<<endl;
    printVerticalOrder(root);
    return 0;
    
}