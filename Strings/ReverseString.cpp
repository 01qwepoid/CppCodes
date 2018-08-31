#include <iostream>
#include<cmath>
using namespace std;
    
void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}    

void reverse(string &s, int start, int end){
    if(end-start<1)
        return;
    reverse(s,start+1, end-1);
    swap(s[start], s[end]);
}

int main() {
    string s = "abcde";
    int start = 0;
    int end = s.length()-1;
    reverse(s,start,end);
    cout<<s<<endl;
    return 0;
}