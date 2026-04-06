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

int main(){
	int n; cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];

	int hist[200021]={};
	rep(i,n) hist[a[i]]++;

	mint dp[2][200021];
	dp[0][0]=1;
	int cur=0,next=1,carry_max=0;
	rep(x,200020){
		int next_carry_max=(carry_max+hist[x+1])/2;
		rep(j,next_carry_max+1) dp[next][j]=0;

		rep(j,carry_max+1){
			// for(int c=0;c<=hist[x+1]+j;c+=2){
			// 	dp[next][c/2]+=dp[cur][j];
			// }
			dp[next][0]+=dp[cur][j];
			dp[next][(hist[x+1]+j)/2+1]-=dp[cur][j];
		}
		rep(j,next_carry_max+1) dp[next][j+1]+=dp[next][j];
		carry_max=next_carry_max;

		swap(cur,next);
	}
	cout<<dp[cur][0]<<endl;

	return 0;
}
