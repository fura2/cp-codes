#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m,x; scanf("%d%d%d",&n,&m,&x);
	vector<int> c(n);
	vector<vector<int>> a(n,vector<int>(m));
	rep(i,n){
		scanf("%d",&c[i]);
		rep(j,m) scanf("%d",&a[i][j]);
	}

	int ans=INF;
	rep(S,1<<n){
		int cost=0;
		vector<int> b(m);
		rep(i,n) if(S>>i&1) {
			cost+=c[i];
			rep(j,m) b[j]+=a[i][j];
		}
		bool ok=true;
		rep(j,m) if(b[j]<x) ok=false;
		if(ok) ans=min(ans,cost);
	}
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
