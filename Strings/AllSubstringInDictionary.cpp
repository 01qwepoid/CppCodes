#include<bits/stdc++.h>
using namespace std;

bool dictionaryContains(string word){
	string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    for(int i=0;i<n;i++){
    	if(dictionary[i].compare(word) ==0)
    		return 1;
    } 
    return 0;
}

bool wordBreak(string str){
//	int n = str.size();
	int n = str.length();
//IMPORTANT : str.length() and str.size() are basically one and the same thing. They can be used interchangably.

	if(n==0)
		return 1;
	for(int i=1;i<=n;i++){
		if(dictionaryContains(str.substr(0,i)) && wordBreak(str.substr(i,n-i)))
			return 1;
	}
	return 0;
}
int main(){
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}