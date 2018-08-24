//fast exponentiation

#include <iostream>
using namespace std;

int power(int a, int n){
    if(n==0)
        return 1;
    if(n==1)
        return a;
    
    int r = power(a, n/2);
    if(n%2)
        return r*a*r;
    return r*r;
}

int main() {
	cout<<power(2,26);
	return 0;
}
