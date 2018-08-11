//Egg-drop puzzle
#include <bits/stdc++.h>
using namespace std;

int eggdropdp(int eggs, int floors){
    int table[eggs+1][floors+1];
    int c= 0;
    for(int i =0;i<=floors;i++)
        table[1][i] = i;
    for(int e =2;e<=eggs;e++){
        for(int f = 1;f<=floors;f++){
            table[e][f] = INT_MAX;
            for(int k = 1;k<=f;k++){
                c =1+max(table[e-1][k-1], table[e][f - k]);
                if(c<table[e][f])
                    table[e][f] = c;
            }
        }
    }
    return table[eggs][floors];
}

int eggdropdp(int eggs, int floors){    
    int table[eggs+1][floors+1];
    int res;
    int i, j, x;
 
    for (i = 1; i <= eggs; i++){
        table[i][1] = 1;
        table[i][0] = 0;
    }
    for (j = 1; j <= floors; j++)
        table[1][j] = j;
    for (i = 2; i <= eggs; i++){
        for (j = 2; j <= floors; j++){
            table[i][j] = INT_MAX;
            for (x = 1; x <= j; x++){
                res = 1 + max(table[i-1][x-1], table[i][j-x]);
                if (res < table[i][j])
                    table[i][j] = res;
            }
        }
    }
    return table[n][k];
}


int eggdrop(int eggs,int floors){
    if(eggs ==1)
        return floors;
    if(floors == 0)
        return 0;
    
    int min = 1000;
    for(int i = 1;i<=floors;i++){
        int val = 1+ max(eggdrop(eggs-1,i-1), eggdrop(eggs, floors - i));
        if(val<min)
            min = val;
    }
    return min;
}

int main() {
//	int r = eggdrop(3,10);
    int r = eggdropdp(3,100);
	cout<<r<<endl;
	return 0;
}
