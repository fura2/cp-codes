#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m,r; cin>>n>>m>>r;
	int s[8];
	rep(i,r) cin>>s[i], s[i]--;
	int d[200][200];
	rep(u,n) rep(v,n) d[u][v]=(u==v?0:INF);
	rep(i,m){
		int u,v,c; cin>>u>>v>>c; u--; v--;
		d[u][v]=d[v][u]=c;
	}

	rep(k,n) rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	int ans=INF;
	int p[]={0,1,2,3,4,5,6,7};
	do{
		int tmp=0;
		rep(i,r-1) tmp+=d[s[p[i]]][s[p[i+1]]];
		ans=min(ans,tmp);
	}while(next_permutation(p,p+r));
	cout<<ans<<endl;

	return 0;
}
