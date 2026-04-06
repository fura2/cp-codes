#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=m.inverse(); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }

	mint inverse()const{
		int a=x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

int main(){
	int n,m,s,t; scanf("%d%d%d%d",&n,&s,&t,&m); s--; t--;
	vector<vector<int>> G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	int d[100];
	mint dp[100];
	rep(u,n){
		d[u]=(u==s?0:-1);
		dp[u]=(u==s?1:0);
	}

	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();

		for(int v:G[u]){
			if(d[v]==-1){
				d[v]=d[u]+1;
				dp[v]=dp[u];
				Q.emplace(v);
			}
			else if(d[v]==d[u]+1){
				dp[v]+=dp[u];
			}
		}
	}

	printf("%d\n",dp[t].to_int());

	return 0;
}
