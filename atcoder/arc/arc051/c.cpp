#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=1e9+7;

lint modpow(lint a,lint k,int m){
	lint r=1;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

int main(){
	int n;
	lint c,k; scanf("%d%lld%lld",&n,&c,&k);

	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	if(c==1){
		rep(i,n) printf("%lld\n",a[i]);
		return 0;
	}

	while(k>0 && c*a[0]<=a[n-1]){
		a[0]*=c;
		k--;
		sort(a.begin(),a.end());
	}

	rep(i,n) a[i]=a[i]%MOD*modpow(c,k/n,MOD)%MOD;
	rep(i,k%n) a[i]=a[i]*c%MOD;
	rotate(a.begin(),a.begin()+k%n,a.end());

	rep(i,n) printf("%lld\n",a[i]);

	return 0;
}
