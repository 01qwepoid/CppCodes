#include <bits/stdc++.h>
using namespace std;

struct interval{
    int s,e;
};

bool compare(interval c, interval d){
    return (c.s < d.s);
}
    
void mergeIntervals(interval a[], int n){
    if(n<=0)
        return;
    
    sort(a,a+n,compare);    
    
    stack<interval> st;
    st.push(a[0]);
    
    for(int i=1;i<n;i++){
        interval top = st.top();
        if(a[i].s > top.e)
            st.push(a[i]);
        else{
            top.e = max(top.e, a[i].e);
            st.pop();
            st.push(top);
        }
    }
    cout << "\n The Merged Intervals are: ";
    while (!st.empty())
    {
        interval t = st.top();
        cout << "[" << t.s << "," << t.e << "] ";
        st.pop();
    }
    return;
}

int main() {
    interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
	return 0;
}
