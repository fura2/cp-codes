#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=LLONG_MAX;

int main(){
	int n,K; cin>>n>>K;
	int x[50],y[50];
	rep(i,n) cin>>x[i]>>y[i];

	vector<int> X(x,x+n),Y(y,y+n);
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	rep(i,n){
		x[i]=lower_bound(X.begin(),X.end(),x[i])-X.begin();
		y[i]=lower_bound(Y.begin(),Y.end(),y[i])-Y.begin();
	}

	int sum[51][51]={};
	rep(i,n) sum[y[i]+1][x[i]+1]++;
	rep(i,50) rep(j,50) sum[i+1][j+1]+=sum[i+1][j]+sum[i][j+1]-sum[i][j];

	lint ans=INF;
	rep(j,Y.size()) rep(i,j) rep(l,X.size()) rep(k,l) {
		int cnt=sum[j+1][l+1]-sum[j+1][k]-sum[i][l+1]+sum[i][k];
		if(cnt>=K) ans=min(ans,1LL*(X[l]-X[k])*(Y[j]-Y[i]));
	}
	cout<<ans<<endl;

	return 0;
}
