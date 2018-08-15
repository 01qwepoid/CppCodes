#include <bits/stdc++.h>
using namespace std;

struct trieNode{
	struct trieNode *children[26];
	bool isleaf;
}

struct trieNode *getNode(){
	struct trieNode *pnode = new trieNode;
	if(pnode){
		int i;
		for(i=0;i<26;i++){
			pnode->children[i] = NULL;
		}
	}
	return pnode;
}

void insert(struct trieNode* root, string key){
	int length = key.length();
	int index;

	struct trieNode *pcrawl = root;
	for(int level = 0;level<length;level++){
		index = CHAR_TO_INDEX(key[level]);
		if(!pcrawl->children[index])
			pcrawl->children[index] = getNode();
		pcrawl = pcrawl->children[index];
	}
	pcrawl->isleaf = 1;
}

int countChildren(struct trieNode *node, int *index){
	int count  =0;
	for(int i=0;i<26;i++){
		if(node->children[i]!=NULL){
			count++;
			*index = i;
		}
	}
	return count;
}

string walkTrie(struct trieNode *root){
	struct trieNode *pcrawl = root;
	int index;
	string prefix;
	while(countChildren(pcrawl, &index)==1 && pcrawl->isleaf == 0){
		pcrawl = pcrawl->children[index];
		prefix.push_back('a' + index);
	}
	return prefix;
}

void constructTrie(string arr[], int n, struct trieNode *root){
	for(int i=0;i<n;i++)
		insert(root, arr[i]);
	return;
}

string commonPrefix(string arr[], int n){
	string trieNode* root = getNode();
	constructTrie(arr, n,root);

	return walkTrie(root);
}

int main(){
	string arr = ["hamburry","hamburgerandsalad","ham","hamsandwich"];
	int n = sizeof(arr)/sizeof(arr[0]);
	string and = commonPrefix(arr,n);
	if(ans.length())
		cout<<"length of longest prefix is "<<ans<<endl;
	cout<<"No common prefix exists."<<endl;
	return 0;
}