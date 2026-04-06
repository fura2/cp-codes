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

struct state{
	int type;
	int u,v,cost,id;
	bool operator<(const state& S)const{ return tie(cost,type)>tie(S.cost,S.type); }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<state> Ev;
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		state S;
		S.type=0;
		S.u=u;
		S.v=v;
		S.cost=c;
		Ev.emplace_back(S);
	}

	int q; scanf("%d",&q);
	rep(i,q){
		int u,c; scanf("%d%d",&u,&c); u--;
		state S;
		S.type=1;
		S.u=u;
		S.cost=c;
		S.id=i;
		Ev.emplace_back(S);
	}

	sort(Ev.begin(),Ev.end());

	vector<int> ans(q);
	union_find U(n);
	for(auto e:Ev){
		if(e.type==0) U.unite(e.u,e.v);
		else          ans[e.id]=U.size(e.u);
	}

	rep(i,q) printf("%d\n",ans[i]);

	return 0;
}
