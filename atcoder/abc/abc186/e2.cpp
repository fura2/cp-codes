#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint modinv(lint a,lint m){
	lint b=m,u=1,v=0;
	while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
	return (u+m)%m;
}

void solve(){
	lint n,s,k; scanf("%lld%lld%lld",&n,&s,&k);

	lint g=gcd(k,n);
	if(s%g!=0){
		puts("-1");
	}
	else{
		n/=g;
		s/=g;
		k/=g;
		printf("%lld\n",modinv(k,n)*(n-s)%n);
	}
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
