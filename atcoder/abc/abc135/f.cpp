#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;
using graph=vector<vector<int>>;

using rolling_hash=pair<lint,lint>;

const lint base=10007,mod1=1e9+7,mod2=998244353;

lint modpow(lint a,lint k,int m){
	lint r=1;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

bool is_DAG(const graph& G){
	int n=G.size();
	vector<int> deg(n);
	rep(u,n) for(int v:G[u]) deg[v]++;

	int cnt=0;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		cnt++;
		for(int v:G[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return cnt==n;
}

vector<int> topological_order(const graph& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(int v:D[u]) deg[v]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(int v:D[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return res;
}

int main(){
	string s,t; cin>>s>>t;

	int m=s.length(),n=t.length();
	lint basepow1=modpow(base,n,mod1);
	lint basepow2=modpow(base,n,mod2);

	rolling_hash ht;
	rep(i,n){
		ht.first =(ht.first *base+t[i])%mod1;
		ht.second=(ht.second*base+t[i])%mod2;
	}

	vector<rolling_hash> hs(m);
	rep(i,n){
		hs[0].first =(hs[0].first *base+s[i%m])%mod1;
		hs[0].second=(hs[0].second*base+s[i%m])%mod2;
	}
	rep(i,m-1){
		hs[i+1].first =(hs[i].first *base-s[i%m]*basepow1+s[(n+i)%m])%mod1;
		hs[i+1].second=(hs[i].second*base-s[i%m]*basepow2+s[(n+i)%m])%mod2;
		if(hs[i+1].first <0) hs[i+1].first +=mod1;
		if(hs[i+1].second<0) hs[i+1].second+=mod2;
	}

	graph G(m);
	rep(u,m) if(ht==hs[u]) G[u].emplace_back((u+n)%m);

	if(!is_DAG(G)) return puts("-1"),0;

	vector<int> dp(m);
	auto p=topological_order(G);
	for(int i=m-1;i>=0;i--){
		int u=p[i];
		for(int v:G[u]) dp[u]=dp[v]+1;
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
