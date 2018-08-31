//Armstrong number
#include <iostream>
#include<cmath>
using namespace std;

int main() {
	int n = 1634, temp = n, count = 0;
	
	while(temp){
	    temp/=10;
	    count++;
	}
	temp = n;
	int sum = 0;
	for(int i =0;i<count;i++){
	    sum +=pow(temp%10,count);
	    temp/=10;
	}
	(sum==n)?cout<<1<<endl:cout<<0<<endl;
	return 0;
}
