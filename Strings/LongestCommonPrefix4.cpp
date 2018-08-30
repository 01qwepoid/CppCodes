//longest common prefix matching

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s[] = {"Geek","Geeks","Gee","GeeksforGeeks","Ham"};
    string prefix = s[0];
    int n = sizeof(s)/ sizeof(s[0]);
    int j,idx;
    for(int i =1;i<n;i++){
        j =0,idx = 0;;
        while(j<s[i].length() && j<prefix.length()){
            if(s[i][j]!=prefix[j]){
                if(j==0){
                    cout<<-1<<endl;
                    return 0;
                }
                prefix = prefix.substr(0,j);
                break;
            }
            j++;
            idx ++;
        }
        if(idx == s[i].length())
            prefix = s[i];
    }
    cout<<prefix<<endl;
    return 0;
}