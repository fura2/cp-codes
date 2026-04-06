#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int mx=0,g=0;
	rep(i,n) mx=max(mx,a[i]), g=gcd(g,a[i]);

	puts(k%g==0&&k<=mx?"POSSIBLE":"IMPOSSIBLE");

	return 0;
}
