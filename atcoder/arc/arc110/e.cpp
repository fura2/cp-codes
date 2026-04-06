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

int main(){
	int n;
	string s; cin>>n>>s;

	if(count(s.begin(),s.end(),'A')==n
	|| count(s.begin(),s.end(),'B')==n
	|| count(s.begin(),s.end(),'C')==n){
		puts("1");
		return 0;
	}

	int f[128];
	f['A']=1;
	f['B']=2;
	f['C']=3;

	vector<int> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]^f[s[i]];

	vector<mint> dp(n+1);
	dp[0]=1;
	int pos[4]={-1,-1,-1,-1}; // pos[x] = (j <= i かつ cum[j] = x となる最大の j)
	rep(i,n){
		pos[cum[i]]=i;

		if(cum[i+1]==0) dp[i+1]+=1;
// naive
/*
		for(int j=i;j>=0;j--) if((cum[i+1]^cum[j])==1) {
			dp[i+1]+=dp[j];
			break;
		}
		for(int j=i;j>=0;j--) if((cum[i+1]^cum[j])==2) {
			dp[i+1]+=dp[j];
			break;
		}
		for(int j=i;j>=0;j--) if((cum[i+1]^cum[j])==3) {
			dp[i+1]+=dp[j];
			break;
		}
*/
		for(int x=1;x<=3;x++){
			int j=pos[cum[i+1]^x];
			if(j!=-1) dp[i+1]+=dp[j];
		}
	}
	if(cum[n]==0) dp[n]-=1;
	cout<<dp[n]<<'\n';

	return 0;
}
