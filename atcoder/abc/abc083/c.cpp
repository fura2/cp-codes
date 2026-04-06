#include <iostream>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	long long x,y;
	cin>>x>>y;

	int i;
	for(i=0;x*(1LL<<i)<=y;i++);
	cout<<i<<endl;

	return 0;
}
