#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int sum[51][51]={};
	rep(i,n) rep(j,n) {
		scanf("%d",&sum[i+1][j+1]);
		sum[i+1][j+1]+=sum[i+1][j]+sum[i][j+1]-sum[i][j];
	}

	int mx[2501]={};
	rep(b,n+1) rep(t,b) rep(r,n+1) rep(l,r) {
		mx[(b-t)*(r-l)]=max(mx[(b-t)*(r-l)],sum[b][r]-sum[b][l]-sum[t][r]+sum[t][l]);
	}
	rep(i,n*n) mx[i+1]=max(mx[i+1],mx[i]);

	int q; scanf("%d",&q);
	rep(_,q){
		int p; scanf("%d",&p);
		printf("%d\n",mx[p]);
	}

	return 0;
}
