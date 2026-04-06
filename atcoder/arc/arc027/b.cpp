#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	vector<int> a;
public:
	union_find(int n):a(n,-1){}
	int find(int x){
		if(a[x]<0) return x;
		return a[x]=find(a[x]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){ a[x]+=a[y]; a[y]=x; }
	}
	int size(int x){ return -a[find(x)]; }
};

int main(){
	int n;
	string s,t; cin>>n>>s>>t;

	union_find U(128);
	bool b[128]={};
	rep(i,n){
		int u=(isupper(s[i])?s[i]:0);
		int v=(isupper(t[i])?t[i]:0);
		U.unite(u,v);
		b[u]=b[v]=true;
	}

	long long ans=1;
	set<int> S={U.find(0)};
	for(char c='A';c<='Z';c++) if(b[c]) {
		int u=U.find(c);
		if(S.count(u)==1) continue;
		S.emplace(u);

		if(u==U.find(s[0]) || u==U.find(t[0])) ans*=9;
		else ans*=10;
	}
	cout<<ans<<endl;

	return 0;
}
