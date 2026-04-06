#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,W; scanf("%d%d",&n,&W);
	int w[3000],v[3000];
	rep(i,n) scanf("%d%d",&w[i],&v[i]);

	static int dpl[3001][3001],dpr[3001][3001];
	rep(i,n){
		rep(x,W+1) dpl[i+1][x]=dpl[i][x];
		for(int x=W;x>=w[i];x--) dpl[i+1][x]=max(dpl[i+1][x],dpl[i][x-w[i]]+v[i]);
		rep(x,W-1) dpl[i+1][x+1]=max(dpl[i+1][x+1],dpl[i+1][x]);
	}
	for(int i=n-1;i>=0;i--){
		rep(x,W+1) dpr[i][x]=dpr[i+1][x];
		for(int x=W;x>=w[i];x--) dpr[i][x]=max(dpr[i][x],dpr[i+1][x-w[i]]+v[i]);
		rep(x,W-1) dpr[i][x+1]=max(dpr[i][x+1],dpr[i][x]);
	}

	int ans=0;
	rep(i,n){
		for(int x=W-1;x>=0;x--){
			int y=W-x-1;
			ans=max(ans,dpl[i][x]+v[i]+dpr[i+1][y]);
		}
	}
	printf("%d\n",ans);

	return 0;
}
