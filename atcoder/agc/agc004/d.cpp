#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class endomorphism_monoid{
	vector<int> f;
public:
	endomorphism_monoid(){}
	endomorphism_monoid(const vector<int>& f):f(f){}
	endomorphism_monoid operator*(const endomorphism_monoid& a)const{
		int n=f.size(),m=a.f.size();
		int k=max(n,m);
		vector<int> res(k);
		rep(i,k){
			int x=(i<m?a.f[i]:i);
			res[i]=(x<n?f[x]:x);
		}
		return res;
	}
	int operator[](int i)const{ return i<f.size()?f[i]:i; }
};

template<class M>
M pow(M f,long long k){
	M res;
	for(;k>0;k>>=1){
		if(k&1) res=res*f;
		f=f*f;
	}
	return res;
}

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> f(n);
	rep(u,n) scanf("%d",&f[u]), f[u]--;

	auto g=pow(endomorphism_monoid(f),k);

	bool ok=true;
	rep(u,n) if(g[u]!=0) ok=false;
	if(ok){
		puts("0");
		return 0;
	}

	int ans=0;
	if(f[0]!=0){
		f[0]=0;
		ans++;
	}
	graph T(n);
	for(int u=1;u<n;u++){
		add_directed_edge(T,f[u],u);
	}
	auto dfs=[&](auto&& dfs,int u)->int{
		int dep=0;
		for(int v:T[u]){
			dep=max(dep,dfs(dfs,v));
		}
		dep++;
		if(dep==k && u!=0 && f[u]!=0){
			ans++;
			dep=0;
		}
		return dep;
	};
	dfs(dfs,0);
	printf("%d\n",ans);

	return 0;
}
