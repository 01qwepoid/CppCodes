//Collect max coins moving down, right

/*
[[0,0,0,0,1,0],
 [0,1,0,1,0,0],
 [0,0,0,1,0,1],
 [0,0,1,0,0,1],
 [0,0,0,0,1,0]
 ]
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> A{{0,0,0,0,1,0},{0,1,0,1,0,0},{0,0,0,1,0,1},{0,0,1,0,0,1},{0,0,0,0,1,0}};
    vector<vector<int>> B = A;
    for(int i =0;i<A.size();i++){
        for(int j = 0;j<A[0].size();j++){
            B[i][j] = 0;
            if(i==0 && j==0 && A[0][0] == 1){
                B[0][0] = 1;
                continue;
            }
            if(i-1>=0 && j-1>=0)
                B[i][j] = max(B[i-1][j], B[i][j-1]);
            else if(j-1>0)
                B[i][j] = B[i][j-1];
            else if(i-1>0)
                B[i][j] = B[i-1][j];
                
            if(A[i][j]==1)
                B[i][j]++;
        }
    }
    cout<<B[A.size()-1][A[0].size()-1];
    
    return 0;
}
