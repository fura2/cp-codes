#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph G;
vector<int> wt;

vector<bool> vis;

int dfs(int u,int p,bool one){
	vis[u]=true;

	int res=0;
	for(int v:G[u]) if(v!=p) res+=dfs(v,u,false);

	int c;
	if(p==-1){
		c=(one?wt[u]/2:0);
		wt[u]-=c;
	}
	else{
		c=min(wt[u],wt[p]);
		wt[u]-=c;
		wt[p]-=c;
	}
	res+=c;

	return res;
}

int solve_odd(vector<int> a){
	vector<int> X=a;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	int n=X.size();
	G.assign(n,{});
	rep(u,n){
		rep(t,31){
			int v=lower_bound(X.begin(),X.end(),(1<<t)-X[u])-X.begin();
			if(v<X.size() && X[u]+X[v]==(1<<t) && u<v){
				add_edge(G,u,v);
			}
		}
	}
	wt.assign(n,0);
	for(int x:a){
		int u=lower_bound(X.begin(),X.end(),x)-X.begin();
		wt[u]++;
	}
	vis.assign(n,false);

	int res=0;
	rep(u,n) if(!vis[u]) res+=dfs(u,-1,X[u]==1);
	return res;
}

int solve(vector<int> a){
	vector<int> E,O;
	for(int x:a){
		if(x%2==0) E.emplace_back(x/2);
		else       O.emplace_back(x);
	}
	return (E.empty()?0:solve(E))+(O.empty()?0:solve_odd(O));
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	printf("%d\n",solve(a));

	return 0;
}
