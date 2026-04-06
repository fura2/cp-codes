#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n;
vector<int> T[100000];
int num[100000];
int parity[100000],l[100000],r[100000];

bool dfs1(int u,int p){
	if(num[u]!=-1){
		if(parity[u]!=num[u]%2) return false;
		l[u]=num[u];
		r[u]=num[u]+1;
	}
	else{
		l[u]=-INF;
		r[u]=INF;
	}

	for(int v:T[u]) if(v!=p) {
		parity[v]=(parity[u]+1)%2;
		if(!dfs1(v,u)) return false;
		l[u]=max(l[u],l[v]-1);
		r[u]=min(r[u],r[v]+1);
	}
	if(l[u]>=r[u]) return false;

	return true;
}

void dfs2(int u,int p){
	if(num[u]==-1){
		if(l[u]<=num[p]-1 && num[p]-1<r[u]) num[u]=num[p]-1;
		else                                num[u]=num[p]+1;
	}

	for(int v:T[u]) if(v!=p) dfs2(v,u);
}

int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}
	int k; scanf("%d",&k);
	rep(u,n) num[u]=-1;
	rep(i,k){
		int u; scanf("%d",&u); u--;
		scanf("%d",num+u);
	}

	int root;
	rep(u,n) if(num[u]!=-1) root=u;
	parity[root]=num[root]%2;

	if(!dfs1(root,-1)){ puts("No"); return 0; }

	dfs2(root,-1);

	puts("Yes");
	rep(u,n) printf("%d\n",num[u]);

	return 0;
}
