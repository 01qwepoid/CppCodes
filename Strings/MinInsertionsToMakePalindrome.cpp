int lcs(string A, string rev, int m, int n){
    int table[n+1][n+1];
    for(int i =0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(i==0 ||j==0)
                table[i][j] = 0;
            else if(A[i] == rev[j])
                table[i][j] = table[i-1][j-1] +1;
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }
    return table[n][n];
}

int findinsertions(string A) {
    int n = A.length();
    string rev = A;
    reverse(rev.begin(),rev.end());
    
    return(n - lcs(A, rev, n, n));
}

int main(){
    string a = "banana";
    cout<<findinsertions(a);
    return 0;
}