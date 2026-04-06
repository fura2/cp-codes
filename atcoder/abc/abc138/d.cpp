#include <cstdio>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
vector<int> G[200000];
int ans[200000];

void dfs(int u,int p){
	for(int v:G[u]) if(v!=p) ans[v]+=ans[u], dfs(v,u);
}

int main(){
	int q;
	scanf("%d%d",&n,&q);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	rep(_,q){
		int p,x; scanf("%d%d",&p,&x); p--;
		ans[p]+=x;
	}

	dfs(0,-1);

	rep(u,n) printf("%d ",ans[u]);

	return 0;
}
