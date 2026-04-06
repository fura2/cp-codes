#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

vector<vector<int>> cycles(const vector<int>& f){
	int n=f.size();
	vector<vector<int>> res;
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		int v=u;
		do{ color[v]=u; v=f[v]; }while(color[v]==-1);
		if(color[v]==u){
			vector<int> C;
			int w=v;
			do{ C.emplace_back(v); v=f[v]; }while(v!=w);
			res.emplace_back(C);
		}
	}
	return res;
}

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> p(n),w(n);
	rep(u,n) scanf("%d",&p[u]), p[u]--;
	rep(u,n) scanf("%d",&w[u]);

	auto C=cycles(p);
	vector<int> id(n);
	rep(i,C.size()) for(int u:C[i]) id[u]=i;

	vector<lint> wsum(C.size());
	rep(i,C.size()) for(int u:C[i]) wsum[i]+=w[u];

	lint ans=-INF;
	rep(u0,n){
		int k_tmp=k;

		lint res=0;
		int len=C[id[u0]].size();
		int m=max(k/len-1,0);
		k-=m*len;
		if(wsum[id[u0]]>0){
			res=m*wsum[id[u0]];
			ans=max(ans,res);
		}
		for(int u=u0;k>0;k--){
			u=p[u];
			res+=w[u];
			ans=max(ans,res);
		}

		k=k_tmp;
	}
	printf("%lld\n",ans);

	return 0;
}
