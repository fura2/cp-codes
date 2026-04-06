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

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

int main(){
	int a[5][5];
	rep(i,5) rep(j,5) scanf("%d",&a[i][j]);

	int m=0;
	pair<int,int> pos[20]; // pos[i] := i 番目の空きマスの位置
	int inv[5][5]; // inv := inverse of pos
	rep(i,5) rep(j,5) if(a[i][j]==0) {
		pos[m]={i,j};
		inv[i][j]=m++;
	}

	mint dp[1<<20]={1};
	int k=0;
	for(int num=1;num<=25;num++){
		int i0=-1,j0;
		rep(i,5) rep(j,5) if(a[i][j]==num) tie(i0,j0)=tie(i,j);

		int p[20]={};
		rep(i,k) p[m-i-1]=1;
		do{
			int S=0;
			rep(i,m) if(p[i]==1) S|=1<<i;

			auto lower=[=](int y,int x){
				return (a[y][x]!=0 && a[y][x]<num) || (a[y][x]==0 && S>>inv[y][x]&1);
			};

			if(i0==-1){ // num is not filled from the beginning
				rep(i,m) if(p[i]==0) {
					int y,x; tie(y,x)=pos[i];
					bool ok=true;
					if(1<=y && y<=3 && lower(y-1,x)!=lower(y+1,x)) ok=false;
					if(1<=x && x<=3 && lower(y,x-1)!=lower(y,x+1)) ok=false;
					if(ok) dp[S|1<<i]+=dp[S];
				}
			}
			else{
				bool ok=true;
				if(1<=i0 && i0<=3 && lower(i0-1,j0)!=lower(i0+1,j0)) ok=false;
				if(1<=j0 && j0<=3 && lower(i0,j0-1)!=lower(i0,j0+1)) ok=false;
				if(!ok) dp[S]=0;
			}
		}while(next_permutation(p,p+m));

		if(i0==-1) k++;
	}

	printf("%d\n",dp[(1<<m)-1].to_int());

	return 0;
}
