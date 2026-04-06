#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int MOD;
class mint{
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

mint operator+(long long y,const mint& m){ return m+y; }
mint operator*(long long y,const mint& m){ return m*y; }

int main(){
	int n;
	string s; cin>>n>>MOD>>s;

	if(MOD==2 || MOD==5){
		lint ans=0;
		rep(i,n) if((s[i]-'0')%MOD==0) ans+=i+1;
		printf("%lld\n",ans);
		return 0;
	}

	vector<int> cnt(MOD);
	mint x=0,ten=1;
	for(int i=n-1;i>=0;i--){
		x+=ten*(s[i]-'0');
		cnt[x.to_int()]++;
		ten*=10;
	}

	lint ans=0;
	x=0; ten=1;
	for(int i=n-1;i>=0;i--){
		ans+=cnt[x.to_int()];
		x+=ten*(s[i]-'0');
		cnt[x.to_int()]--;
		ten*=10;
	}
	printf("%lld\n",ans);

	return 0;
}
