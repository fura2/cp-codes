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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

mint fact(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=memo[k-1]*k;
	}
	return memo[n];
}

mint fact_inverse(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		memo[n]=inverse(fact(n));
		for(int i=n;i>k;i--) memo[i-1]=memo[i]*i;
	}
	return memo[n];
}

mint choose(int n,int k,int type=0){
	if(k==0) return 1;
	if(n< k) return 0;
	if(type==0){
		return fact(n)*fact_inverse(k)*fact_inverse(n-k);
	}
	else{
		if(k>n-k) k=n-k;
		mint res=fact_inverse(k);
		rep(i,k) res*=n-i;
		return res;
	}
}

int k;
bool vis[17][200001];
mint memo[17][200001];

mint calc(int c,int rem){ // すでに c 種類の数字を使っていて, rem 箇所のスロットを自由に決められる
	if(vis[c][rem]) return memo[c][rem];
	vis[c][rem]=true;
	mint& res=memo[c][rem];

	if(c>k || k-c>rem) return res=0;

	res=0;
	rep(i,k-c+1) res+=(i%2==0?1:-1)*choose(k-c,i)*pow(mint(k-i),rem);
	res*=choose(16-c,k-c);
	return res;
}

int main(){
	string s;
	cin>>s>>k;
	int n=s.length();

	int f[128];
	rep(i,10) f['0'+i]=i;
	rep(i,6) f['A'+i]=10+i;

	mint ans=0;
	int c=0; // 使った数字の種類数
	vector<int> cnt(16); // cnt[i] = (数字 i を使った個数)

	// leading zero なし
	rep(i,n){
		int d=f[s[i]];
		rep(j,d) if(!(i==0 && j==0)) {
			if(cnt[j]==0) c++;
			cnt[j]++;
			ans+=calc(c,n-i-1);
			cnt[j]--;
			if(cnt[j]==0) c--;
		}
		if(cnt[d]==0) c++;
		cnt[d]++;
	}
	ans+=calc(c,0);

	// leading zero あり
	c=0;
	fill(cnt.begin(),cnt.end(),0);
	for(int i=1;i<n;i++){
		rep(j,16) if(j>0) {
			if(cnt[j]==0) c++;
			cnt[j]++;
			ans+=calc(c,n-i-1);
			cnt[j]--;
			if(cnt[j]==0) c--;
		}
	}

	cout<<ans<<'\n';

	return 0;
}
