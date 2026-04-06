#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct edge{ int u,v,w; };

const int INF=1<<30;

int main(){
	int n,m,p; scanf("%d%d%d",&n,&m,&p);
	edge E[5000];
	rep(i,m){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
		E[i].u--; E[i].v--; E[i].w-=p;
	}

	int d[2500];
	rep(u,n) d[u]=(u==0?0:INF);
	bool neg[2500]={};
	rep(t,4*n) rep(i,m) {
		int u=E[i].u,v=E[i].v,w=-E[i].w;
		if(d[u]<INF && d[v]>d[u]+w){
			d[v]=d[u]+w;
			if(t>=n-1) neg[v]=true;
		}
	}

	// set of vertices reachable from n-1 in the reversed graph
	bool vis[2500]={};
	vis[n-1]=true;
	rep(t,n) rep(i,m) {
		int u=E[i].u,v=E[i].v;
		if(vis[v]) vis[u]=true;
	}

	rep(u,n) if(neg[u] && vis[u]) { puts("-1"); return 0; }

	printf("%d\n",max(-d[n-1],0));

	return 0;
}
