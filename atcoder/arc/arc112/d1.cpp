#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

int solve(vector<string> B){
	int h=B.size(),w=B[0].size();

	union_find U(h+w-3);
	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		int u,v;
		if(i==0 || i==h-1) u=h+w-4;
		else               u=i-1;
		if(j==0 || j==w-1) v=h+w-4;
		else               v=h-2+j-1;
		U.unite(u,v);
	}

	set<int> S;
	for(int i=h-2;i<h+w-3;i++) S.emplace(U.find(i));
	return S.size()-1;
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int ans=h*w;
	rep(_,2){
		ans=min(ans,solve(B));

		vector<string> B2(w,string(h,'?'));
		rep(i,h) rep(j,w) B2[j][i]=B[i][j];
		B=B2;
	}
	cout<<ans<<'\n';

	return 0;
}
