#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x0,k,d; cin>>x0>>k>>d;
	x0=abs(x0);

	if(x0/d>=k){
		cout<<x0-k*d<<'\n';
	}
	else if(x0/d%2==k%2){
		cout<<x0%d<<'\n';
	}
	else{
		cout<<d-x0%d<<'\n';
	}

	return 0;
}
