//all ones
#include <iostream>
using namespace std;
#define R 3
#define C 4
int main() {

	int mat[R][C] = { { 1, 0, 0, 1 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 0, 0 } };
    
    int rowflag[R], colflag[C];
    for(int i =0;i<R;i++){
        for(int j =0;j<C;j++){
            if(mat[i][j] == 1){
                rowflag[i] =1;
                colflag[j] =1;
            }
        }
    }
    for(int i =0;i<R;i++){
        for(int j =0;j<C;j++){
            if(rowflag[i] == 1){
                mat[i][j] = 1;
            }
            if(colflag[j]==1)
                mat[i][j] = 1;
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
