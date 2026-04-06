#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
	mint operator-()const{ return mint(-x); }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	if(k==n){
		mint ans=1;
		rep(i,n) ans*=a[i];
		cout<<ans<<'\n';
		return 0;
	}

	vector<lint> p,m;
	rep(i,n){
		if(a[i]>=0) p.emplace_back(a[i]);
		else        m.emplace_back(a[i]);
	}
	sort(p.rbegin(),p.rend());
	sort(m.begin(),m.end());

	if(m.size()==n){
		mint ans=1;
		if(k%2==0){
			rep(i,k) ans*=m[i];
		}
		else{
			rep(i,k) ans*=m[n-1-i];
		}
		cout<<ans<<'\n';
		return 0;
	}

	mint ans=1;
	int pidx=0,midx=0;
	if(k%2==1) ans*=p[pidx++], k--;
	while(k>0){
		if(pidx+1>=p.size()){
			ans*=m[midx++];
			ans*=m[midx++];
		}
		else if(midx+1>=m.size()){
			ans*=p[pidx++];
			ans*=p[pidx++];
		}
		else if(p[pidx]*p[pidx+1]>=m[midx]*m[midx+1]){
			ans*=p[pidx++];
			ans*=p[pidx++];
		}
		else{
			ans*=m[midx++];
			ans*=m[midx++];
		}
		k-=2;
	}
	cout<<ans<<'\n';

	return 0;
}
