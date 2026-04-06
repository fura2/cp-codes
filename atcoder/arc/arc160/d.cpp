#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using lint=long long;

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

mint factorial(lint n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=memo[k-1]*k;
	}
	return memo[n];
}

mint factorial_inverse(lint n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		memo[n]=inverse(factorial(n));
		for(int i=n;i>k;i--) memo[i-1]=memo[i]*i;
	}
	return memo[n];
}

mint choose(lint n,lint k,int type=0){
	if(k==0) return 1;
	if(n< k) return 0;
	if(type==0){
		return factorial(n)*factorial_inverse(k)*factorial_inverse(n-k);
	}
	else{
		if(k>n-k) k=n-k;
		mint res=factorial_inverse(k);
		rep(i,k) res*=n-i;
		return res;
	}
}

mint multichoose(lint n,lint k,int type=0){
	return choose(n+k-1,k,type);
}

int main(){
	lint n,m,k;
	cin>>n>>m>>k;

	if(m%k!=0){
		cout<<0<<'\n';
		return 0;
	}

	mint ans=0;
	rep(i,n-k+2) if(m/k-k*i>=0) {
		ans+=mint(i%2==0?1:-1)*choose(n-k+1,i)*multichoose(2*n-k+1,m/k-k*i,1);
	}
	cout<<ans<<'\n';

	return 0;
}
