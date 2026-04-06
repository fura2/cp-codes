#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint f(lint a){
	if(a==0) return 0;
	if(a==1) return 1;
	if(a==2) return 3;
	if(a==3) return 0;
	int i;
	for(i=62;(a&(1LL<<i))==0;i--);
	return f(a-(1LL<<i))+(a%2==0?(1LL<<i):0);
}

int main(){
	lint a,b; cin>>a>>b;
	cout<<(f(b)^(a>0?f(a-1):0))<<endl;

	return 0;
}
