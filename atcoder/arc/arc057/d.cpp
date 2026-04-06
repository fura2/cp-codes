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
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return -x; }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=t; return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

int n;
vector<vector<int>> P;

void dfs(int r,vector<int>& p){
	if(r==0){
		P.emplace_back(p);
		return;
	}

	for(int i=1;i<=r;i++){
		if(!p.empty() && p.back()<i) break;
		p.emplace_back(i);
		dfs(r-i,p);
		p.pop_back();
	}
}

int main(){
	scanf("%d",&n);
	vector<int> a(n-1);
	rep(i,n-1) scanf("%d",&a[i]);

	vector<int> tmp;
	dfs(n,tmp);

	map<vector<int>,int> f; // partition -> index
	rep(i,P.size()) f[P[i]]=i;

	vector dp(2,vector(P.size(),mint(0)));
	dp[0][f[vector<int>(n,1)]]=1;

	int cur=0,nxt=1,idx=0;
	for(int i=1;i<=n*(n-1)/2;i++){
		fill(dp[nxt].begin(),dp[nxt].end(),mint(0));

		if(idx<n-1 && a[idx]==i){
			rep(j,P.size()){
				if(dp[cur][j].to_int()!=0){
					int m=P[j].size();
					rep(k1,m) for(int k2=k1+1;k2<m;k2++) {
						auto q=P[j];
						q[k1]+=q[k2];
						q.erase(q.begin()+k2);
						sort(q.rbegin(),q.rend());
						dp[nxt][f[q]]+=dp[cur][j]*P[j][k1]*P[j][k2];
					}
				}
			}
			idx++;
		}
		else{
			rep(j,P.size()){
				if(dp[cur][j].to_int()!=0){
					int c=0;
					rep(k,P[j].size()){
						c+=P[j][k]*(P[j][k]-1)/2-(P[j][k]-1);
					}
					c-=i-idx-1;
					if(c>0){
						dp[nxt][j]+=dp[cur][j]*c;
					}
				}
			}
		}
		swap(cur,nxt);
	}
	cout<<dp[cur][f[{n}]]<<'\n';

	return 0;
}
