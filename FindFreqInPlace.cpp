// count freq in O(1) space & O(n) time.
#include <iostream>
#include<cmath>
using namespace std;
    
void freq(int a[], int n){
    for(int i =0;i<n;i++)
        a[i] = a[i] - 1;
    for(int i=0;i<n;i++)
        a[a[i]%n] = a[a[i]%n] +n;
    for(int i =0;i<n;i++){
        cout<<i+1<<" -> "<<a[i]/n<<endl;
    }
    return;   
}
    
int main() {
    int a[] = {2,3,3,2,5};
    int n = sizeof(a)/sizeof(a[0]);
    freq(a,n);
    return 0;
}