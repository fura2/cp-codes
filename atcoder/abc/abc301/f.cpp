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

bool visited[300001][27];
mint memo[300001][27];
mint f(int q,int k){ // q個?がある, 大文字をk種類使用済み
	if(k>26) return 0;

	if(visited[q][k]) return memo[q][k];
	visited[q][k]=true;
	if(q==0) return memo[q][k]=1;
	return memo[q][k]=26*f(q-1,k)+(26-k)*f(q-1,k+1);
}

int main(){
	string s; cin>>s;
	int n=s.length();

	int hist1[128]={};
	rep(i,n) hist1[s[i]]++;
	vector dp2(n+1,vector<mint>(2));
	dp2[n][0]=1;

	mint ans=0;
	for(int i=n-1;i>=0;i--){
		hist1[s[i]]--;

		mint c1=pow(mint(52),hist1['?']); // DD
		bool b=false;
		for(int c='A';c<='Z';c++) if(hist1[c]>=2) b=true;
		if(!b){
			int cnt=count(hist1+'A',hist1+'Z'+1,1);
			c1-=f(hist1['?'],cnt);
		}

		mint c2; // o
		if     (isupper(s[i])) c2=0;
		else if(islower(s[i])) c2=1;
		else                   c2=26;

		mint c3=dp2[i+1][1]; // S
		if(isupper(s[i])){
			dp2[i][0]=0;
			dp2[i][1]=dp2[i+1][0]+dp2[i+1][1];
		}
		else if(islower(s[i])){
			dp2[i][0]=dp2[i+1][0]*1;
			dp2[i][1]=0;
		}
		else{
			dp2[i][0]=dp2[i+1][0]*26;
			dp2[i][1]=(dp2[i+1][0]+dp2[i+1][1])*26;
		}

		ans+=c1*c2*c3;
	}

	cout<<pow(mint(52),count(s.begin(),s.end(),'?'))-ans<<endl;

	return 0;
}
