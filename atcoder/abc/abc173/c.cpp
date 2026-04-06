#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,k; cin>>h>>w>>k;
	string B[6];
	rep(i,h) cin>>B[i];

	int ans=0;
	rep(S,1<<h) rep(T,1<<w) {
		int cnt=0;
		rep(i,h) rep(j,w) if(B[i][j]=='#' && (S>>i&1)==0 && (T>>j&1)==0) cnt++;
		if(cnt==k) ans++;
	}
	cout<<ans<<'\n';

	return 0;
}
