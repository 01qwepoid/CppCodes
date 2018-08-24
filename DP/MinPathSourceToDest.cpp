#include <bits/stdc++.h>
using namespace std;

#define N 4
#define M 4
int minDistance(char grid[N][M]){
    int table[N][M];
    queue <pair<int,int>>q;
    int di,dj;
    for(int i=0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(grid[i][j] == '*')
                table[i][j] = INT_MAX;
            else if(grid[i][j]=='0')
                table[i][j] = -1;
            else if(grid[i][j]=='s'){
                q.push(pair<int,int>(i,j));
                table[i][j] = -1;
            }
            else if(grid[i][j]=='d'){
                table[i][j]==INT_MAX;
                di = i;
                dj = j;
            }
        }
    }
    pair<int, int> ptr;
    ptr = q.front();
    q.pop();
    int ptr1 = ptr.first;
    int ptr2 = ptr.second;
    

    //check if thereis an element on top, ie it's not on the top row
    if(ptr1-1>=0 && (table[ptr1-1][ptr2]> table[ptr1][ptr2] +1)){
        table[ptr1-1][ptr2] = 1;
        q.push(pair<int,int>(ptr1-1, ptr2));
    }

    //check if it is not on the bottom row
    if(ptr1+1<N && (table[ptr1+1][ptr2]> table[ptr1][ptr2] +1)){
        table[ptr1+1][ptr2] = 1;
        q.push(pair<int,int>(ptr1+1, ptr2));
    }

    //check if it's not in the left-most row    
    if(ptr2-1>=0 && (table[ptr1][ptr2-1]> table[ptr1][ptr2] +1)){
        table[ptr1][ptr2-1] = 1;
        q.push(pair<int,int>(ptr1, ptr2-1));
    }
    
    //check if it's not in the left-most row
    if(ptr2+1<M && (table[ptr1][ptr2+1]> table[ptr1][ptr2] +1)){
        table[ptr1][ptr2+1] = 1;
        q.push(pair<int,int>(ptr1, ptr2+1));
    }
    
    while(!q.empty()){
        ptr = q.front();
        q.pop();
        ptr1 = ptr.first;
        ptr2 = ptr.second;
        
        
        
        if(ptr1-1>=0 && (table[ptr1-1][ptr2]> table[ptr1][ptr2] +1)){
            table[ptr1-1][ptr2] = table[ptr1][ptr2] +1;
            q.push(pair<int,int>(ptr1-1, ptr2));
        }
    
        if(ptr1+1<N && (table[ptr1+1][ptr2]> table[ptr1][ptr2] +1)){
            table[ptr1+1][ptr2] = table[ptr1][ptr2] +1;
            q.push(pair<int,int>(ptr1+1, ptr2));
        }
        
        if(ptr2-1>=0 && (table[ptr1][ptr2-1]> table[ptr1][ptr2] +1)){
            table[ptr1][ptr2-1] = table[ptr1][ptr2] +1;
            q.push(pair<int,int>(ptr1, ptr2-1));
        }
    
        if(ptr2+1<M && (table[ptr1][ptr2+1]> table[ptr1][ptr2] +1)){
            table[ptr1][ptr2+1] = table[ptr1][ptr2] +1;
            q.push(pair<int,int>(ptr1, ptr2+1));
        }
        if(ptr1 == di && ptr2 == dj)
            return table[di][dj];

        
    }
    return -1;
}
int main() {
    
    char grid[N][M] = { { '0', '*', '0', 's' },
                        { '*', '0', '*', '*' },
                        { '0', '*', '*', '*' },
                        { 'd', '*', '*', '*' } };
                        
  /*  for(int i =0;i<N;i++){
        for(int j =0;j<M;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }*/
 
    cout << minDistance(grid);
    return 0;
}
