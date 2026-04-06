#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
T xgcd(T a,T b,T& x,T& y){
	if(b==0){ x=1; y=0; return a; }
	T g=xgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}

void solve(){
	lint n,s,k; scanf("%lld%lld%lld",&n,&s,&k);

	lint g=gcd(k,n);
	if(s%g!=0){
		puts("-1");
		return;
	}

	lint x,y;
	xgcd(n,k,x,y);
	y*=-1;
	y*=s/g;
	y%=n/g;
	if(y<0) y+=n/g;
	printf("%lld\n",y);
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
