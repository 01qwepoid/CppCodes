/*
Approch:
1. Do inorder traversal and store elements in a vector
2. Traverse one pointer from left and other from right
3. You will get the result if it exists
*/


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

void insertinorder(treenode *root, vector<int> &v){
    if(!root)
        return;
    insertinorder(root->left, v);
    v.push_back(root->data);
    insertinorder(root->right, v);
}

bool isPairPresent(treenode *root, int sum){
    vector<int> v;
    insertinorder(root, v);
    int i = 0, j = v.size()-1;
    while(i<j){
        if(v[i] + v[j] == sum){
            cout<<v[i] << " and "<<v[j] <<" sum up to "<<sum<<endl;
            return 1;
        }
            
        if(v[i] + v[j] > sum)
            j--;
        else
            i++;
    }
    return 0;
}

int main(){
    /*
                   15
                /     \
              10      20
             / \     /  \
            8  12   16  25    */
    struct treenode *root =  newtreenode(15);
    root->left = newtreenode(10);
    root->right = newtreenode(20);
    root->left->left = newtreenode(8);
    root->left->right = newtreenode(12);
    root->right->left = newtreenode(16);
    root->right->right = newtreenode(25);
 
    int target = 33;
    if (isPairPresent(root, target) == 0)
        printf("\n No such values are found\n");
    return 0;
}