#include<bits/stdc++.h>
using namespace std;

int maxsum(int a[], int n){
    if(n==0)
        return 0;
    int table[n+1];
    table[0] = a[0];
    table[1] = max(table[0], a[1]);
    for(int i =2;i<n;i++){
        table[i] = max(a[i]+table[i-2], table[i-1]);
        table[i] = max(table[i], a[i]);
    }
    return table[n-1];
}

int main(){
    int arr[] = {-1,-20,-3, 4, -6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxsum(arr,n)<<endl;
}