#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }
template<class T> T lcm(const T& a,const T& b){ return a/gcd(a,b)*b; }

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]), a[i]/=2;

	vector<int> c(n);
	rep(i,n) for(int t=a[i];t%2==0;t/=2) c[i]++;

	rep(i,n-1) if(c[0]!=c[i+1]) return puts("0"),0;

	lint L=1;
	rep(i,n){
		L=lcm(L,a[i]);
		if(L>m) return puts("0"),0;
	}
	printf("%lld\n",(m/L+1)/2);

	return 0;
}
