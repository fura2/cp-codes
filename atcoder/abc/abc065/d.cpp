#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size(){ return n; }
	int size(int u){ return -p[find(u)]; }
};

int main(){
	int n; cin>>n;
	vector<int> x(n),y(n);
	rep(i,n) cin>>x[i]>>y[i];

	vector<pair<int,int>> X(n),Y(n);
	rep(i,n){
		X[i]={x[i],i};
		Y[i]={y[i],i};
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());

	vector<pair<int,pair<int,int>>> E;
	rep(i,n-1){
		E.emplace_back(X[i+1].first-X[i].first,make_pair(X[i].second,X[i+1].second));
		E.emplace_back(Y[i+1].first-Y[i].first,make_pair(Y[i].second,Y[i+1].second));
	}
	sort(E.begin(),E.end());

	lint ans=0;
	union_find U(n);
	for(auto e:E){
		int u=e.second.first,v=e.second.second;
		if(!U.is_same(u,v)){
			U.unite(u,v);
			ans+=e.first;
		}
	}
	cout<<ans<<endl;

	return 0;
}
