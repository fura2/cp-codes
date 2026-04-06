#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	int d[10][10];
	rep(i,10) rep(j,10) cin>>d[i][j];

	rep(k,10) rep(i,10) rep(j,10) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	int ans=0;
	rep(i,h) rep(j,w) {
		int a; cin>>a;
		if(a!=-1) ans+=d[a][1];
	}
	cout<<ans<<endl;

	return 0;
}
