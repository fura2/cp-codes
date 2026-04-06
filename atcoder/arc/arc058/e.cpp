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

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int n,x,y,z;

bool trim(deque<int>& H){ // return true if H is xyz
	int sum=0,i=0;
	while(i<H.size()){
		if(sum+H[i]>x){
			if(i>0){
				sum-=H.front();
				i--;
			}
			H.pop_front();
			continue;
		}
		sum+=H[i];
		i++;
		if(sum==x) break;
	}
	if(i==H.size()) return false;

	sum=0;
	while(i<H.size()){
		if(sum+H[i]>y){
			H.pop_front();
			return trim(H);
		}
		sum+=H[i];
		i++;
		if(sum==y) break;
	}
	if(i==H.size()) return false;

	sum=0;
	while(i<H.size()){
		if(sum+H[i]>z){
			H.pop_front();
			return trim(H);
		}
		sum+=H[i];
		i++;
		if(sum==z) return true;
	}
	return false;
}

map<deque<int>,mint> memo[40][18];

mint dfs(int i,deque<int> H){
	if(i==n) return 1;

	int m=H.size();
	if(memo[i][m].count(H)==1) return memo[i][m][H];

	mint res=0;
	deque<int> H2;
	for(int a=1;a<=7;a++){
		H2.assign(H.begin(),H.end());
		H2.emplace_back(a);
		if(!trim(H2)) res+=dfs(i+1,H2);
	}
	res+=dfs(i+1,{})*3; // 8, 9, 10
	return memo[i][m][H]=res;
}

int main(){
	cin>>n>>x>>y>>z;
	cout<<pow(mint(10),n)-dfs(0,{})<<'\n';
	return 0;
}
