#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,k; cin>>a>>k;
	if(k==0){
		cout<<2000000000000-a<<'\n';
	}
	else{
		int t;
		for(t=0;a<2000000000000;t++) a+=1+k*a;
		cout<<t<<'\n';
	}
	return 0;
}
