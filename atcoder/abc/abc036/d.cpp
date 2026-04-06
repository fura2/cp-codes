#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

class mint{
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint &operator+=(const mint &m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint &operator-=(const mint &m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint &operator*=(const mint &m){ x=1LL*x*m.x%MOD; return *this; }
	mint operator+(const mint &m)const{ return mint(*this)+=m; }
	mint operator-(const mint &m)const{ return mint(*this)-=m; }
	mint operator*(const mint &m)const{ return mint(*this)*=m; }

	friend ostream &operator<<(ostream &os,const mint &m){ return os<<m.x; }
};

int n;
vector<int> T[100000];

bool vis[100000][2];
mint memo[100000][2];

mint dfs(int u,int p,int c){
	if(vis[u][c]) return memo[u][c];
	vis[u][c]=true;

	mint res=1;
	for(int v:T[u]) if(v!=p) {
		mint tmp=dfs(v,u,0);
		if(c==0) tmp+=dfs(v,u,1);
		res*=tmp;
	}
	return memo[u][c]=res;
}

int main(){
	cin>>n;
	rep(i,n-1){
		int u,v; cin>>u>>v; u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	cout<<dfs(0,-1,0)+dfs(0,-1,1)<<endl;

	return 0;
}
