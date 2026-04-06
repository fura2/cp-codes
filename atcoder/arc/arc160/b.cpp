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

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

mint solve(lint n){
	lint n2=sqrt(n);

	lint sum=0;
	for(lint y=1;y<=n2;y++){
		sum+=n/y;
	}

	mint c1=0; // x<y<z
	for(lint x=1;x<=n2;x++){
		// for(lint y=x+1;y<=n2;y++){
		// 	c1+=n/y-y;
		// }
		sum-=n/x; // sum = Σ_{y=x+1}^{n2} floor(n/y)
		c1+=sum;
		c1-=n2*(n2+1)/2-x*(x+1)/2;
	}

	mint c2=0; // x=y<z
	for(lint x=1;x<=n2;x++){
		c2+=n/x-(x+1)+1;
	}

	mint c3=0; // x<y=z
	for(lint y=1;y<=n2;y++){
		c3+=y-1;
	}

	mint c4=n2; // x=y=z

	return 6*c1+3*c2+3*c3+c4;
}

int main(){
	int T; cin>>T;
	while(T--){
		lint n; cin>>n;
		cout<<solve(n)<<endl;
	}
	return 0;
}
