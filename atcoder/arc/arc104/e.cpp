#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
vector<T> longest_increasing_subsequence(const vector<T> &a){
	vector<T> lis;
	for(const auto& x:a){
		auto it=lower_bound(lis.begin(),lis.end(),x);
		if(it!=lis.end()) *it=x;
		else lis.emplace_back(x);
	}
	return lis;
}

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

int n,a[6];

mint calc(const vector<int>& p){
	vector<int> Y={0};
	rep(i,n) Y.emplace_back(a[i]);
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());

	int idx[6];
	function<mint(int)> dfs=[&](int i)->mint{
		if(i==n){
			int b[6];
			rep(j,n) b[j]=idx[p[j]];
			rep(j,n-1) if(b[j]>b[j+1]) return 0;

			mint res=1;
			int pre=0;
			for(int j=1;j<=n;j++){
				if(j==n || b[j-1]<b[j]){
					int len=j-pre,eq=0;
					rep(k,len-1) if(p[pre+k]>p[pre+k+1]) eq++;
					res*=choose(Y[b[pre]+1]-Y[b[pre]]+eq,len,1);
					pre=j;
				}
			}
			return res;
		}

		mint res=0;
		rep(j,int(Y.size())-1){
			if(Y[j+1]>a[i]) break;
			idx[i]=j;
			res+=dfs(i+1);
		}
		return res;
	};
	return dfs(0);
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	mint num=0;
	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	do{
		num+=calc(p)*longest_increasing_subsequence(p).size();
	}while(next_permutation(p.begin(),p.end()));

	mint den=1;
	rep(i,n) den*=a[i];

	cout<<num/den<<'\n';

	return 0;
}
