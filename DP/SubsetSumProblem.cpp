#include<bits/stdc++.h>
using namespace std;

bool issumpossible(int a[], int n, int k){
    bool table[n+1][k+1];
    
    for(int i =0;i<=n;i++){
        for(int j =0;j<=k;j++)
            table[i][j] = 0;
    }
    
    for(int i =0;i<=n;i++){
        for(int j =0;j<=k;j++){
            if(j ==0){
                table[i][j]=1;
                continue;
            }
            if(i ==0){
                table[i][j] = 0;
                continue;
            }
/*
            if(j<a[i-1])
                table[i][j] = table[i-1][j];
            if (j >= a[i-1])
                table[i][j] = table[i-1][j] || 
                                 table[i-1][j-a[i-1]];

*/            
            if(j==a[i-1]){
                table[i][j] = 1;
                continue;
            }
            if(j < a[i-1])
                table[i][j] = table[i-1][j];
            else
                table[i][j] = table[i-1][j] || table[i-1][j-a[i-1]]; 
        }
    }
    return table[n][k];
}

int main(){
    int a[] = {10,15,3,7};
    int k = 22;
    int n = sizeof a/ sizeof a[0];
    cout<<issumpossible(a,n,k)<<endl;
    return 0;
}