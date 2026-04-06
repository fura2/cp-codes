#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> G[100000];
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
	}
	int s,t; scanf("%d%d",&s,&t); s--; t--;

	int d[100000][3];
	rep(u,n) rep(k,3) d[u][k]=INF;
	d[s][0]=0;
	queue<pair<int,int>> Q;
	Q.emplace(s,0);
	while(!Q.empty()){
		auto a=Q.front(); Q.pop();
		int u=a.first,k=a.second;

		if(u==t && k==0){ printf("%d\n",d[u][k]/3); return 0; }

		for(int v:G[u]) if(d[v][(k+1)%3]==INF) {
			d[v][(k+1)%3]=d[u][k]+1;
			Q.emplace(v,(k+1)%3);
		}
	}

	puts("-1");

	return 0;
}
