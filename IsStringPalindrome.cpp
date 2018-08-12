#include <iostream>
#include <string>
using namespace std;

bool ispalindrome(string s){
    string str = s;
    int n = s.length();
    char t;
    for(int i=0;i<n/2;i++){
        t = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = t;
    }
    if(str.compare(s)==0)
        return 1;
    return 0;
}
int main(){
    string s = "apple";
    if(ispalindrome(s))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}