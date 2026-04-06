#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph T;
int sz[100000];

int dfs1(int u,int p){
	sz[u]=1;
	for(int v:T[u]) if(v!=p) sz[u]+=dfs1(v,u);
	return sz[u];
}

int dfs2(int u,int p){
	vector<pair<int,int>> even1,even2,odd;
	for(int v:T[u]) if(v!=p) {
		int tmp=dfs2(v,u);
		if(sz[v]%2==0){
			if(tmp<=sz[v]-tmp){
				even1.emplace_back(tmp,sz[v]);
			}
			else{
				even2.emplace_back(tmp,sz[v]);
			}
		}
		else{
			odd.emplace_back(tmp,sz[v]);
		}
	}

	int res=1;
	rep(i,even1.size()){
		res+=even1[i].first;
	}
	sort(odd.begin(),odd.end(),[](const auto& x,const auto& y){
		return 2*x.first-x.second<2*y.first-y.second;
	});
	rep(i,odd.size()){
		if(i%2==0) res+=odd[i].first;
		else       res+=odd[i].second-odd[i].first;
	}
	sort(even2.begin(),even2.end(),[](const auto& x,const auto& y){
		return 2*x.first-x.second<2*y.first-y.second;
	});
	rep(i,even2.size()){
		if(odd.size()%2==0) res+=even2[i].first;
		else                res+=even2[i].second-even2[i].first;
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	for(int u=1;u<n;u++){
		int p; scanf("%d",&p); p--;
		add_undirected_edge(T,p,u);
	}

	dfs1(0,-1);
	printf("%d\n",dfs2(0,-1));

	return 0;
}
