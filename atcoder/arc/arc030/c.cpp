#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class strongly_connected_components{
	int idx;
	vector<int> top,id;
	const vector<vector<int>>& G;
	vector<vector<int>> G_rev;

	void dfs1(int u){
		id[u]=0;
		for(int v:G[u]) if(id[v]==-1) dfs1(v);
		top[idx++]=u;
	}

	void dfs2(int u){
		id[u]=idx;
		for(int v:G_rev[u]) if(id[v]==-1) dfs2(v);
	}

public:
	vector<vector<int>> DAG;

	strongly_connected_components(const vector<vector<int>>& G):G(G){
		int n=G.size();
		G_rev.resize(n);
		rep(u,n) for(int v:G[u]) G_rev[v].emplace_back(u);

		idx=0;
		id.assign(n,-1);
		top.resize(n);
		rep(u,n) if(id[u]==-1) dfs1(u);

		reverse(top.begin(),top.end());

		idx=0;
		id.assign(n,-1);
		for(int u:top) if(id[u]==-1) dfs2(u), idx++;

		DAG.resize(idx);
		rep(u,n) for(int v:G[u]) if(id[u]!=id[v]) DAG[id[u]].emplace_back(id[v]);
	}

	int operator[](int i)const{ return id[i]; }
};

int main(){
	int n,m,K; cin>>n>>m>>K;
	string s;
	rep(u,n){
		char c; cin>>c;
		s+=c;
	}
	vector<vector<int>> G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
	}

	strongly_connected_components SCC(G);

	int N=SCC.DAG.size();
	vector<string> S(N);
	rep(u,n) S[SCC[u]]+=s[u];
	for(string& t:S) sort(t.begin(),t.end());

	vector<vector<string>> dp(N,vector<string>(K+1,"~"));
	rep(i,N) dp[i][0]="";
	for(int i=N-1;i>=0;i--){
		for(int len=1;len<=K;len++){
			rep(len2,S[i].length()+1){
				if(len2>len) break;
				string tmp=(len>len2?"~":"");
				for(int j:SCC.DAG[i]){
					tmp=min(tmp,dp[j][len-len2]);
				}
				if(tmp!="~"){
					dp[i][len]=min(dp[i][len],S[i].substr(0,len2)+tmp);
				}
			}
		}
	}

	string ans="~";
	rep(i,N) ans=min(ans,dp[i][K]);
	cout<<(ans=="~"?"-1":ans)<<endl;

	return 0;
}
