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

int getMaxWidth(treenode *root){
    if(!root)
        return 0;
    
    queue<treenode*> q;
    q.push(root);
    int result = 0;
    while(!q.empty()){
        int count = q.size();
        result = max(result, count);
        
        while(count--){
            treenode* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return result;
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