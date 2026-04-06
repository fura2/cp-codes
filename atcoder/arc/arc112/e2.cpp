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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

mint factorial(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=memo[k-1]*k;
	}
	return memo[n];
}

mint factorial_inverse(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		memo[n]=inverse(factorial(n));
		for(int i=n;i>k;i--) memo[i-1]=memo[i]*i;
	}
	return memo[n];
}

mint choose(int n,int k,int type=0){
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

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	mint two[3001]={1};
	rep(i,m) two[i+1]=two[i]*2;

	// dp[i][j] = (i 個の区別できるボールを j 個のグループに分ける方法の数) (Stirling number of the second kind)
	mint dp[3001][3002]={};
	dp[0][0]=1;
	rep(i,m){
		rep(j,n+1){
			dp[i+1][j]+=j*dp[i][j]; // ボール i をすでにあるグループのどれかに加える
			dp[i+1][j+1]+=dp[i][j]; // ボール i だけからなる新しいグループを作る
		}
	}

	mint ans=0;
	rep(i,n+1){
		for(int j=i;j<=n;j++){
			int l=i,r=n-j;
			if(l+r<=m){
				ans+=dp[m][l+r]*choose(l+r,l)*two[m-l-r];
			}

			if(i<j && j<n && a[j-1]>a[j]){
				break;
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}
