#include<iostream>
using namespace std;
int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int mat[n][m];
		for(int i=0;i<n;i++){
		    for(int j = 0;j<m;j++){
		       if(i==0 || j ==0)
		            mat[i][j] = 1;
		       else
		           mat[i][j] = (mat[i-1][j]+mat[i][j-1])%1000000007;
		    }
		}
		cout<<mat[n-1][m-1]<<endl;
	}
}