#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

using namespace std;

ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }

int main(){
	ll x,y;
	scanf("%lld/%lld",&x,&y);

	vector<pair<ll,ll>> ans;
	rep(i,2){
		ll n=2*x/y+i;
		if(n<=0) continue;
		ll a=(n+1)*y-2*x;
		if(a<=0) continue;
		ll b=2*y;
		ll g=gcd(a,b);
		a/=g; b/=g;
		ll c=n;
		g=gcd(b,c);
		b/=g; c/=g;
		if(b!=1) continue;
		ll m=a*c;
		if(1<=m && m<=n) ans.emplace_back(n,m);
	}

	if(ans.empty()) puts("Impossible");
	else for(auto a:ans) printf("%lld %lld\n",a.first,a.second);

	return 0;
}
