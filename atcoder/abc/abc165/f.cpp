#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

graph T;
vector<int> val;

vector<int> lis,ans;

void dfs(int u,int p){
	auto it=lower_bound(lis.begin(),lis.end(),val[u]);
	int pos,val_pre;
	if(it==lis.end()){
		pos=-1;
		lis.emplace_back(val[u]);
	}
	else{
		pos=it-lis.begin();
		val_pre=lis[pos];
		lis[pos]=val[u];
	}

	ans[u]=lis.size();
	for(int v:T[u]) if(v!=p) dfs(v,u);

	if(pos==-1) lis.pop_back();
	else        lis[pos]=val_pre;
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	val.resize(n);
	rep(u,n) scanf("%d",&val[u]);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	ans.resize(n);
	dfs(0,-1);

	rep(u,n) printf("%d\n",ans[u]);

	return 0;
}
