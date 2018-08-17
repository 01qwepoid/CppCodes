#include <bits/stdc++.h>
using namespace std;
int main (){
    string s1 ("ilikesamsung");
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};

    
    int size = sizeof(dictionary)/sizeof(dictionary[0]);

    
    for(int i=0;i<size;i++){
        unsigned found = s1.find(dictionary[i]);
//      if (found != string::npos && found <=size){
        if (found != -1){
            cout<<dictionary[i]<<"  ";
            cout << found << '\n'; 
        }
            
    }
    return 0;
}