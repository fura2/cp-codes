// O(N^5) solution

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

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	mint dp1[100][101][101]; // tree
	mint dp2[100][101][101]; // forest
	rep(l,n){
		dp1[l][l+1][1]=1;
	}
	for(int w=1;w<=n;w++){
		rep(l,n-w+1){
			int r=l+w;
			for(int x=2;x<=w;x++){
				if(x<=a[l]){
					dp1[l][r][x]=dp2[l+1][r][x-1];
				}
			}
		}

		rep(l,n-w+1){
			int r=l+w;
			for(int x=1;x<=w;x++){
				dp2[l][r][x]=dp1[l][r][x];
				for(int i=l+1;i<r;i++){
					for(int y=1;y<=x;y++){
						dp2[l][r][x]+=dp2[l][i][y]*dp1[i][r][x];
					}
					if(x<=a[i]){
						for(int y=1;y<x;y++){
							dp2[l][r][x]+=dp2[l][i][x]*dp1[i][r][y];
						}
					}
				}
			}
		}
	}

	mint ans=0;
	rep(x,n+1) ans+=dp2[0][n][x];
	cout<<ans<<'\n';

	return 0;
}
