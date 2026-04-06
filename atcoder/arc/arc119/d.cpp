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
	vector<vector<int>> ans;
	vector<bool> vis(n);
	rep(u,n) if(!vis[u]) {
		vis[u]=true;
		ans.emplace_back();
		queue<int> Q; Q.emplace(u);
		while(!Q.empty()){
			int v=Q.front(); Q.pop();
			ans.back().emplace_back(v);
			for(int w:G[v]) if(!vis[w]) {
				vis[w]=true;
				Q.emplace(w);
			}
		}
	}
	return ans;
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	graph G(h+w);
	rep(i,h) rep(j,w) if(B[i][j]=='R') {
		add_undirected_edge(G,i,h+j);
	}

	int rcnt[2]={},ccnt[2]={};
	vector<tuple<int,int,int>> ans[2];

	for(auto C:connected_components(G)){
		if(C.size()==1) continue;

		int u0=C[0];
		int u1=G[u0][0];
		if(u0>=h) swap(u0,u1);

		int u[2]={u0,u1};
		rep(i,2){
			queue<int> Q; 
			Q.emplace(u[i]);
			vector<bool> vis(h+w);
			vis[u[i]]=true;
			while(!Q.empty()){
				int v=Q.front(); Q.pop();
				for(int z:G[v]) if(!vis[z]) {
					vis[z]=true;
					if(z<h){
						rcnt[i]++;
						ans[i].emplace_back(0,z,v);
					}
					else{
						ccnt[i]++;
						ans[i].emplace_back(1,v,z);
					}
					Q.emplace(z);
				}
			}
		}
	}

	if((h-rcnt[0])*(w-ccnt[0])>(h-rcnt[1])*(w-ccnt[1])){
		swap(ans[0],ans[1]);
	}
	reverse(ans[0].begin(),ans[0].end());

	printf("%ld\n",ans[0].size());
	for(auto [type,u,v]:ans[0]){
		printf("%c %d %d\n",type==0?'X':'Y',u+1,v-h+1);
	}

	return 0;
}
