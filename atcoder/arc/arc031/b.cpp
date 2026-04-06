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

bool check(string B[10]){
	int cnt=0;
	rep(i,10) rep(j,10) if(B[i][j]=='x') cnt++;

	union_find U(100);
	rep(i,10) rep(j,10) if(B[i][j]=='o') {
		if(i<9 && B[i+1][j]=='o') U.unite(i*10+j,(i+1)*10+j);
		if(j<9 && B[i][j+1]=='o') U.unite(i*10+j,i*10+(j+1));
	}
	return U.size()==cnt+1;
}

int main(){
	string B[10];
	rep(i,10) cin>>B[i];

	rep(i,10) rep(j,10) if(B[i][j]=='x') {
		B[i][j]='o';
		if(check(B)) return puts("YES"),0;
		B[i][j]='x';
	}
	puts("NO");

	return 0;
}
