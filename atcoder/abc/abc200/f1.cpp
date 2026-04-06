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
	mint& operator*=(const mint& m){ x=(long long)x*m.x%MOD; return *this; }
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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

mint count01(string s,lint k){ // s * k の先頭の文字を 0 で固定したときの 01 を数える
	int n=s.length();
	int m=count(s.begin(),s.end(),'?');

	mint res=0;
	rep(i,n){
		char c1=s[i],c2=s[(i+1)%n];
		if(c1!='1' && c2!='0'){ // 01
			// 1 周目
			{
				lint q=k*m; // ? の個数
				if(c1=='?') q--;
				if(c2=='?') q--;
				if(s[0]=='?' && i>0) q--;
				if(i<n-1 || (i==n-1 && k>=2)){
					res+=pow(mint(2),q);
				}
			}
			// 2 周目以降
			if(k>=2){
				lint q=k*m;
				if(c1=='?') q--;
				if(c2=='?') q--;
				if(s[0]=='?') q--;
				res+=pow(mint(2),q)*(i<n-1?k-1:k-2);
			}
		}
	}
	return res;
}

mint count10(string s,lint k){ // s * k の先頭の文字を 1 で固定したときの 10 を数える
	int n=s.length();
	int m=count(s.begin(),s.end(),'?');

	mint res=0;
	rep(i,n){
		char c1=s[i],c2=s[(i+1)%n];
		if(c1!='0' && c2!='1'){ // 10
			// 1 周目
			{
				lint q=k*m; // ? の個数
				if(c1=='?') q--;
				if(c2=='?') q--;
				if(s[0]=='?' && i>0) q--;
				if(i<n-1 || (i==n-1 && k>=2)){
					res+=pow(mint(2),q);
				}
			}
			// 2 周目以降
			if(k>=2){
				lint q=k*m;
				if(c1=='?') q--;
				if(c2=='?') q--;
				if(s[0]=='?') q--;
				res+=pow(mint(2),q)*(i<n-1?k-1:k-2);
			}
		}
	}
	return res;
}

int main(){
	string s;
	lint k; cin>>s>>k;

	mint ans=0;
	if(s[0]!='1') ans+=count01(s,k);
	if(s[0]!='0') ans+=count10(s,k);
	cout<<ans<<'\n';

	return 0;
}
