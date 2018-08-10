//Egg-drop puzzle
#include <bits/stdc++.h>
using namespace std;

int eggdropdp(int eggs, int floors){
    
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
	int r = eggdrop(3,10);
	cout<<r<<endl;
	return 0;
}
