#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	vector<int> v(n);
	rep(i,n) v[i]=(s[i]=='o');

	vector<int> ans(n);
	rep(i,2) rep(j,2) {
		ans[0]=i;
		ans[1]=j;
		rep(x,n-2) ans[x+2]=(ans[x+1]==v[x+1]?ans[x]:!ans[x]);

		bool ng=false;
		ng|=(ans[ 0 ]==v[ 0 ])^(ans[1]==ans[n-1]);
		ng|=(ans[n-1]==v[n-1])^(ans[0]==ans[n-2]);
		if(!ng){
			rep(i,n) cout<<(ans[i]?'S':'W');
			cout<<'\n';
			return 0;
		}
	}
	cout<<"-1\n";

	return 0;
}
