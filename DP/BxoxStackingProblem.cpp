#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

struct box{
    int l,b,h;
};

bool compare(box one, box two){
    return one.l*one.b < two.l*two.b;
}

int boxStacking(vector<box> boxes, int n){
    //vector to store all the results
    vector<int> lis(3*n);
    //lis[i] : maximum height attainable by including box i at bottom
    
    int i,j;
    //initialization
    for(int i =0;i<3*n;i++)
        lis[i] = boxes[i].h;
    
    //implement lis
    for(i=1;i<3*n;i++){
        for(int j=0;j<i;j++){
            if(boxes[j].l < boxes[i].l && boxes[j].b < boxes[i].b){
                if(lis[i]< lis[j] + boxes[i].h)
                    lis[i] = lis[j] + boxes[i].h;
            }
        }
    }
    int maxheight = lis[0];
    for(int i =1 ;i<3*n;i++){
        if(lis[i]>maxheight)
            maxheight = lis[i];
    }
    return maxheight;
}

int main() {
    int n, l, b,h;
    n = 3;
    vector<box> boxes(n*3);
    int a[] = {1,2,3,2,3,4,4,5,6};
    
	for(int i=0;i<3*n;i++){
	    l = a[i];
	    b = a[i+1];
	    h = a[i+2];
	    
	    boxes[i].l = min(b,h);
	    boxes[i].b = max(b,h);
	    boxes[i].h = l;
	    i++;
	    boxes[i].l = min(l,b);
	    boxes[i].b = max(l,b);
	    boxes[i].h = h;
	    i++;
	    boxes[i].l = min(l,h);
	    boxes[i].b = max(l,h);
	    boxes[i].h = b;
	}
	
	//sort based on area - increasing
	sort(boxes.begin(), boxes.end(),compare);
	cout<<"Highest height = ";
	cout<<boxStacking(boxes,n);
	cout<<endl;
	return 0;
}
