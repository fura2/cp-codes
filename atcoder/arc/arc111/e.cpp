#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

long long floor_sum(long long n,long long m,long long a,long long b){
	long long res=0;
	if(a>=m){
		res+=n*(n-1)/2*(a/m);
		a%=m;
	}
	if(b>=m){
		res+=n*(b/m);
		b%=m;
	}

	long long y_max=(a*(n-1)+b)/m;
	if(y_max==0) return res;
	return res+y_max+floor_sum(y_max,a,m,(a*(n-1)+b)-m*y_max);
}

void solve(){
	lint a,b,c,d; scanf("%lld%lld%lld%lld",&a,&b,&c,&d);

	lint T=(d-2)/(c-b);
	printf("%lld\n",T-floor_sum(T+1,d,c,a)+floor_sum(T+1,d,b,a-1));
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
