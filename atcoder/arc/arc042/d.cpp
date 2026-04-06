#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint modinv(lint a,lint m){
	lint b=m,u=1,v=0;
	while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
	return (u+m)%m;
}

lint modpow(lint a,lint n,int m){
	lint r=1;
	for(lint x=a%m;n>0;n>>=1,x=x*x%m) if(n&1) r=r*x%m;
	return r;
}

int modlog(lint a,lint b,int p){
	a%=p; if(a<0) a+=p;
	b%=p; if(b<0) b+=p;

	int k=sqrt(p)+1,c=1;
	vector<pair<int,int>> H(k);
	rep(j,k) H[j]={c,j}, c=c*a%p;
	sort(H.begin(),H.end());

	c=modinv(c,p);
	rep(i,k){
		auto it=lower_bound(H.begin(),H.end(),make_pair((int)b,0));
		if(it!=H.end() && it->first==b) return i*k+(it->second);
		b=b*c%p;
	}
	return -1;
}

int main(){
	int x,p,a,b; cin>>x>>p>>a>>b;

	lint ans=p;
	if(b-a<(1<<25)){
		lint y=modpow(x,a,p);
		rep(i,b-a+1){ ans=min(ans,y); y=y*x%p; }
	}
	else{
		lint t=modinv(modpow(x,a,p),p); // x^{-a}
		for(int z=0;;z++){
			int i=modlog(x,z*t,p);
			if(i!=-1 && i<=b-a){ ans=z; break; }
		}
	}
	cout<<ans<<'\n';

	return 0;
}
