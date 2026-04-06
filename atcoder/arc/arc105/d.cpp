#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	if(n%2==0){
		map<int,int> f;
		rep(i,n) ++f[a[i]];
		bool ok=true;
		for(auto p:f) if(p.second%2==1) ok=false;
		puts(!ok?"First":"Second");
	}
	else{
		puts("Second");
	}
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
