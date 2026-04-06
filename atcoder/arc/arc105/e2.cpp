#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

vector<vector<int>> connected_components(const graph& G){
	int n=G.size();
	vector<vector<int>> res;
	vector<bool> vis(n);
	rep(u,n) if(!vis[u]) {
		vis[u]=true;
		res.emplace_back();
		queue<int> Q; Q.emplace(u);
		while(!Q.empty()){
			int v=Q.front(); Q.pop();
			res.back().emplace_back(v);
			for(int w:G[v]) if(!vis[w]) {
				vis[w]=true;
				Q.emplace(w);
			}
		}
	}
	return res;
}

bool dfs(int turn,int a,int b,vector<int> c){
	if(c.empty()){
		if(turn==0) return !(a<2 && b<2) && !(2<=a && 2<=b);
		else        return  (a<2 && b<2) ||  (2<=a && 2<=b);
	}

	rep(i,c.size()){
		int a2,b2;
		vector<int> c2;

		// c[i] を a にマージ
		a2=(a+c[i])%4; b2=b;
		c2=c;
		c2.erase(c2.begin()+i);
		if(!dfs(1-turn,a2,b2,c2)) return true;

		// c[i] を b にマージ
		a2=a; b2=(b+c[i])%4;
		c2=c;
		c2.erase(c2.begin()+i);
		if(!dfs(1-turn,a2,b2,c2)) return true;

		for(int j=i+1;j<c.size();j++){
			// c[i] と c[j] をマージ
			a2=a; b2=b;
			c2={(c[i]+c[j])%4};
			rep(k,c.size()) if(k!=i && k!=j) c2.emplace_back(c[k]);
			if(!dfs(1-turn,a2,b2,c2)) return true;
		}
	}
	return false;
}

void solve(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}

	auto CC=connected_components(G);

	int a,b,c[4]={};
	for(auto C:CC){
		bool has_a=false,has_b=false;
		for(int u:C){
			if(u== 0 ) has_a=true;
			if(u==n-1) has_b=true;
		}
		if     (has_a) a=C.size()%4;
		else if(has_b) b=C.size()%4;
		else           c[C.size()%4]++;
	}
	c[1]%=4;
	c[3]%=4;
	c[2]%=2;

	vector<int> t;
	for(int x=1;x<=3;x++) rep(_,c[x]) t.emplace_back(x);
	puts(dfs(m%2,a,b,t)?"First":"Second");
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
