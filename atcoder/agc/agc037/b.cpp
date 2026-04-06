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

mint fact(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=memo[k-1]*k;
	}
	return memo[n];
}

int main(){
	int n;
	string s; cin>>n>>s;

	mint ans=fact(n);
	int r=0,g=0,b=0;
	for(char c:s){
		if(c=='R'){
			if(g>0 && b>0){
				ans*=min(g,b);
				g--;
				b--;
			}
			else{ // g = 0 or b = 0
				if(max(g,b)>r){
					if(g>r){
						ans*=g-r;
					}
					else{ // b > r
						ans*=b-r;
					}
				}
				r++;
			}
		}
		else if(c=='G'){
			if(r>0 && b>0){
				ans*=min(r,b);
				r--;
				b--;
			}
			else{
				if(max(r,b)>g){
					if(r>g){
						ans*=r-g;
					}
					else{
						ans*=b-g;
					}
				}
				g++;
			}
		}
		else{ // c = 'B'
			if(r>0 && g>0){
				ans*=min(r,g);
				r--;
				g--;
			}
			else{
				if(max(r,g)>b){
					if(r>b){
						ans*=r-b;
					}
					else{
						ans*=g-b;
					}
				}
				b++;
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}
