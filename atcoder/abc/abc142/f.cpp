#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; cin>>n>>m;
	vector<int> G[1000];
	rep(i,m){
		int u,v; cin>>u>>v; u--; v--;
		G[u].emplace_back(v);
	}

	vector<int> ans;
	rep(u,n){
		int d[1000],pre[1000];
		bool vis[1000]={};
		queue<int> Q; Q.push(u);
		rep(v,n) d[v]=INF;
		d[u]=0;
		vis[u]=true;
		while(!Q.empty()){
			int v=Q.front(); Q.pop();
			for(int w:G[v]){
				if(!vis[w]){
					vis[w]=true;
					d[w]=d[v]+1;
					pre[w]=v;
					Q.push(w);
				}
				else if(w==u){
					vector<int> tmp;
					tmp.emplace_back(v);
					int z=pre[v];
					while(z!=u) tmp.emplace_back(z), z=pre[z];
					tmp.emplace_back(u);
					if(ans.empty() || tmp.size()<ans.size()) ans=tmp;
				}
			}
		}
	}

	if(ans.empty()) cout<<-1<<endl;
	else{
		cout<<ans.size()<<endl;
		for(int x:ans) cout<<x+1<<endl;
	}

	return 0;
}
