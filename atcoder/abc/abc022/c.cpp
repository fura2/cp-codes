#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);

	int d[300][300];
	rep(u,n) rep(v,n) d[u][v]=(u==v?0:INF);

	vector<edge<int>> A;
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		if(u==0){
			A.emplace_back(v,c);
		}
		else{
			d[u][v]=d[v][u]=c;
		}
	}

	rep(k,n) rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	int ans=INF;
	for(auto e:A) for(auto f:A) if(e.to!=f.to) ans=min(ans,e.wt+d[e.to][f.to]+f.wt);
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
