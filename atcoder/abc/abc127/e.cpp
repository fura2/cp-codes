#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

using namespace std;

const ll MOD=1000000007;

ll xgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){ x=1; y=0; return a; }
	ll g=xgcd(b,a%b,y,x); y-=a/b*x;
	return g;
}

ll modinv(ll a,ll m){
	ll x,y;
	if(xgcd(a,m,x,y)==1) return (x+m)%m;
	return -1;
}

int main(){
	ll h,w,k; cin>>h>>w>>k;

	ll a=1; // hw-2 choose k-2
	rep(i,k-2) a=a*(h*w%MOD-i-2)%MOD*modinv(k-i-2,MOD)%MOD;

	ll b=0; // sum_{i=1}^{w-1} i(w-i)
	rep(i,w-1) b=(b+(i+1)*(w-i-1)%MOD)%MOD;

	ll c=0; // sum_{i=1}^{h-1} i(h-i)
	rep(i,h-1) c=(c+(i+1)*(h-i-1)%MOD)%MOD;

	cout<<a*(h*h%MOD*b%MOD+w*w%MOD*c%MOD)%MOD<<endl;

	return 0;
}
