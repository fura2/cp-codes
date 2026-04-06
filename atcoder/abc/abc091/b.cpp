#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	map<string,int> f;
	int n; cin>>n;
	rep(i,n){ string s; cin>>s; ++f[s]; }
	int m; cin>>m;
	rep(i,m){ string s; cin>>s; --f[s]; }

	int ans=0;
	for(auto x:f) ans=max(ans,x.second);
	cout<<ans<<endl;

	return 0;
}
