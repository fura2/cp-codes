#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,k; cin>>a>>b>>k;

	if(k<=a){
		cout<<a-k<<' '<<b<<'\n';
	}
	else{
		cout<<"0 "<<max(a+b-k,0LL)<<'\n';
	}

	return 0;
}
