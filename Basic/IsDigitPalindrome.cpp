#include <iostream>
using namespace std;
bool ispalindrome(int n){
    if(!(n/10))
        return 1;
    int t=n;
    int rev=0,dig = 0;
    do{
        dig = n%10;
        rev = rev*10 + dig;
        n/=10;
    }
    while(n);
    if(t==rev)
        return 1;
    return 0;
}

int main() {
	int a = 556;
	if(ispalindrome(a))
	    cout<<"Yes"<<endl;
	else 
	    cout<<"No"<<endl;
	return 0;
}
