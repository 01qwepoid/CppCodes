//rotten oranges
// 1 - fresh
// 2 - rotten
// 0 - empty place 

#include <bits/stdc++.h>
#define R 3
#define C 5

using namespace std;

//to store coordinates of cell
struct ele{
    int x, y;
};

bool isdelim(ele temp){
    return (temp.x==-1 && temp.y == -1);
}

bool isvalid(int i, int j){
    return (i>= 0 && j>=0 && i<R && j<C); 
}

bool checkall(int arr[][C]){
    for(int i=0;i<R;i++)
        for(int j =0;j<C;j++)
            if(arr[i][j]==1)
                return 1;
    return 0;
}

int rotOranges(int arr[][C]){
    queue<ele> q;
    ele temp;
    int ans = 0;
    
    //insert all rotten oranges into queue
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(arr[i][j]==2){
                temp.x = i;
                temp.y = j;
                q.push(temp);
            }
        }
    }
    
    //insert delimiter to calculate for time
    temp.x = -1;
    temp.y = -1;
    q.push(temp);
    
    while(!q.empty()){
        //to check if even a single orange rot in the current time frame
        bool flag = 0;
        
        //process all rotten eggs in current time
        while(!isdelim(q.front())){
            temp = q.front();
            
            //check down
            if(isvalid(temp.x+1, temp.y) && arr[temp.x +1][temp.y] == 1){
                
                //if this is the first orange to rot, then set flag, and increase ans(time)
                if(!flag){
                    ans++;
                    flag=1;
                }
                arr[temp.x+1][temp.y] = 2;
                
                //push this cell to queue
                temp.x++;
                q.push(temp);
                
                temp.x--; //move back to current cell
            }
            //check up
            if(isvalid(temp.x-1, temp.y) && arr[temp.x -1][temp.y] == 1){
                if(!flag){
                    ans++;
                    flag=1;
                }
                arr[temp.x-1][temp.y] = 2;
                temp.x--;
                q.push(temp);
                temp.x++; //move back to current cell
            }
            //check left
            if(isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1){
                if(!flag){
                    ans++;
                    flag=1;
                }
                arr[temp.x][temp.y-1] = 2;
                temp.y--;
                q.push(temp);
                temp.y++; //move back to current cell
            }
            //check right
            if(isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 1){
                if(!flag){
                    ans++;
                    flag=1;
                }
                arr[temp.x][temp.y+1] = 2;
                temp.y++;
                q.push(temp);
                temp.y--; //move back to current cell // no need at the end
            }
            q.pop();
        }
        //pop the delimiter
        q.pop();
        
        //if oranges were rotten, in this time frame, insert another delimiter
        if(!q.empty()){
            temp.x = -1;
            temp.y = -1;
            q.push(temp);
        }
    }
    return (checkall(arr))? -1:ans;
}


int main() {
	int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rot\n";
    else
         cout << "Time required for all oranges to rot => " << ans << endl;
    return 0;
}
