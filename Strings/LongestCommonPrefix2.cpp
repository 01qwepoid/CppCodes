#include <iostream>
#include <string>
//#include<bits/stdc++.h>
using namespace std;

int main() {
	string arr[] = {"hamburry","hamburgerandsalad","ham","hamsandwich"};
	string aaa[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
	string prefix = aaa[0];
	int n = sizeof(aaa)/sizeof(arr[0]);
	if(n==1)
	    return prefix;
	for(int i=1;i<n;i++){
	    int j = 0;
	    while(prefix[j] == aaa[i][j]){
	        j++;
	    }
	    prefix = prefix.substr(0,j);
	}
	cout<<prefix<<endl;
	return 0;
}
