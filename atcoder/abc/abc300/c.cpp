#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int n=min(h,w);
	vector<int> ans(n);
	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		int len=n,d;
		for(d=1;;d++) if(i+d<0 || h<=i+d || j+d<0 || w<=j+d || B[i+d][j+d]!='#') break;
		len=min(len,d-1);
		for(d=1;;d++) if(i+d<0 || h<=i+d || j-d<0 || w<=j-d || B[i+d][j-d]!='#') break;
		len=min(len,d-1);
		for(d=1;;d++) if(i-d<0 || h<=i-d || j+d<0 || w<=j+d || B[i-d][j+d]!='#') break;
		len=min(len,d-1);
		for(d=1;;d++) if(i-d<0 || h<=i-d || j-d<0 || w<=j-d || B[i-d][j-d]!='#') break;
		len=min(len,d-1);
		if(len>0) ans[len-1]++;
	}
	rep(i,n) cout<<ans[i]<<" ";

	return 0;
}
