#include <bits/stdc++.h>

#define bool int
struct node{
   int data;
   struct node* left;
   struct node* right;
};

struct node* newnode(int data){
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
bool hasPathSum(node *root, int sum){
  if(!root)
      return sum = 0;
  bool ans = 0;
  int subsum = sum - root->data;
  if(subsum ==0 && !root->left && !root->right)
      return 1;
  if(node->left)
      ans = ans || hasPathSum(root->left);
  if(node->right)
      ans = ans || hasPathSum(root->right);
  return ans;
}

int main(){
  int sum = 21;
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
 
  if(hasPathSum(root, sum))
    printf("There is a root-to-leaf path with sum %d", sum);
  else
    printf("There is no root-to-leaf path with sum %d", sum);
 
  getchar();
  return 0;
}