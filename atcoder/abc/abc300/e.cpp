#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=998244353;
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

map<tuple<int,int,int>,mint> memo;
mint dfs(int c2,int c3,int c5){
	if(c2<0 || c3<0 || c5<0){
		return 0;
	}
	if(c2==0 && c3==0 && c5==0){
		return 1;
	}

	if (memo.count({c2,c3,c5})>0) return memo[{c2,c3,c5}];
	return memo[{c2,c3,c5}]=(dfs(c2-1,c3,c5)+dfs(c2,c3-1,c5)+dfs(c2-2,c3,c5)+dfs(c2,c3,c5-1)+dfs(c2-1,c3-1,c5))/5;
}

int main(){
	int64_t n;
	cin>>n;

	int c2=0,c3=0,c5=0;
	while(n%2==0) c2++, n/=2;
	while(n%3==0) c3++, n/=3;
	while(n%5==0) c5++, n/=5;

	if(n>1){
		cout<<"0"<<endl;
		return 0;
	}

	cout<<dfs(c2,c3,c5)<<endl;

	return 0;
}
