#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	int s[10]={};
	rep(i,m){
		int k; cin>>k;
		rep(j,k){ int a; cin>>a; a--; s[a]|=1<<i; }
	}
	int p[10];
	rep(i,m) cin>>p[i];

	int ans=0;
	rep(S,1<<n){
		int x=0;
		rep(i,n) if(S&(1<<i)) x^=s[i];
		rep(i,m) x^=p[i]<<i;
		if(x==0) ans++;
	}
	cout<<ans<<endl;

	return 0;
}
