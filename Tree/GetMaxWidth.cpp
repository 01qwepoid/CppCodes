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

int getwidth(treenode *root, int level){
    if(!root)
        return 0;
    if(level ==1)
        return 1;
    return getwidth(root->left, level-1) + getwidth(root->right, level-1);
}
int getMaxWidth(treenode *root){
    int maxwidth = 0;
    int width;
    int h = height(root);
    for(int i =1;i<=h;i++){
        width = getwidth(root, i);
        if(width> maxwidth)
            maxwidth = width;
    }
    return maxwidth;
}

int main(){
  struct treenode *root = newtreenode(1);
  root->left        = newtreenode(2);
  root->right       = newtreenode(3);
  root->left->left  = newtreenode(4);
  root->left->right = newtreenode(5);
  root->right->right = newtreenode(8);    
  root->right->right->left  = newtreenode(6);    
  root->right->right->right  = newtreenode(7);      
 
  /*
   Constructed bunary tree is:
          1
        /  \
       2    3
     /  \     \
    4   5     8 
              /  \
             6   7
  */ 
  printf("Maximum width is %d \n", getMaxWidth(root));  
  getchar();
  return 0;
}