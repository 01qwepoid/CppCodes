#include<iostream>
using namespace std;

int minjumps(int a[], int n){
    int maxreach = a[0],j=1,jump= 1,temp = a[0];
    while(maxreach <n){
        while(j<=maxreach){
            temp = max(temp, a[j]+j);
            j++;
            if(temp>=n-1){
                jump++;
                return jump;
            }
        }
        maxreach = temp;
        jump++;
        if(j>maxreach)
            return -1;
    }
    return jump;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i =0;i<n;i++)
            cin>>a[i];
        if(a[0]==0){
            cout<<-1<<endl;
            continue;
        }
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        cout<<minjumps(a,n)<<endl;
    }
    return 0;
}