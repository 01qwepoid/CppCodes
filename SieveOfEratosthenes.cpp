#include <bits/stdc++.h>
using namespace std;
    
void SieveOfEratosthenes(int n){
    int table[n+1];
    memset(table, 0, sizeof(table));
    for(int i =2;i*i<=n;i++){
        if(table[i]==0){
            for(int j=i*2;j<=n;j+=i)
                table[j] = 1;
        }
    }
    for(int i = 2;i<=n;i++){
        if(table[i]==0)
            cout<<i<<" ";  
    }
}    

int main() {
    int n = 50;
    SieveOfEratosthenes(n);
    return 0;
}