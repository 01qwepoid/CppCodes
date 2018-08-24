//fast exponentiation

#include <iostream>
using namespace std;

int power(int a, int n, int m){
    if(n==0)
        return 1;
    if(n==1)
        return a%m;
    
    int r = power(a, n/2)%m;
    if(n%2)
        return (r*a*r)%m;
    return (r*r)%m;
}

int main() {
	cout<<power(2,26, 50);
	return 0;
}
