#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

unsigned long long xor64(){
	static unsigned long long x=88172645463325252LL;
	x^=(x<<13);
	x^=(x>>7);
	return x^=(x<<17);
}

lint modpow(lint a,lint n,lint m){
	lint r=1;
	for(lint x=a%m;n;n>>=1,x=(x*x)%m) if(n&1) r=(r*x)%m;
	return r;
}

lint primitive_root(lint p){
	vector<lint> pf;
	lint tmp=p-1;
	for(lint q=2;q*q<=tmp;q++) if(tmp%q==0) {
		pf.emplace_back(q);
		do tmp/=q; while(tmp%q==0);
	}
	if(tmp>1) pf.emplace_back(tmp);

	while(1){
		lint g=xor64()%(p-1)+1;
		bool ok=true;
		rep(i,pf.size()) if(modpow(g,(p-1)/pf[i],p)==1) { ok=false; break; }
		if(ok) return g;
	}
}

int main(){
	int p,a,b; scanf("%d%d%d",&p,&a,&b);

	int r=primitive_root(p);
	vector<int> f(p); // (Z/pZ)^x -> (Z/(p-1)Z, +)
	vector<int> g(p); // f^{-1}
	{
		lint x=1,y=0;
		rep(i,p){
			f[x]=y;
			g[y]=x;
			x=x*r%p;
			y++;
		}
	}

	a=f[a];
	b=f[b];

	if(gcd(gcd(a,b),p-1)>1){
		puts("No");
		return 0;
	}

	// periods
	int pa=(p-1)/gcd(a,p-1);
	int pb=(p-1)/gcd(b,p-1);

	if(pb==p-1){
		swap(a,b);
		swap(pa,pb);
	}
	if(pa==p-1){
		vector<int> res(p);
		rep(i,p-1) res[i+1]=(res[i]+a)%(p-1);
		puts("Yes");
		rep(i,p) printf("%d%c",g[res[i]],i<p-1?' ':'\n');
		return 0;
	}

	if(pb%2==1){
		swap(a,b);
		swap(pa,pb);
	}
	assert(pb%2==0 && (p-1)%pb==0);
	pa=(p-1)/pb;

	vector<int> res={0};
	rep(i,pa-1) res.emplace_back((res.back()+a)%(p-1));
	rep(j,pb-1){
		res.emplace_back((res.back()+b)%(p-1));
		if(j%2==0){
			rep(i,pa-2) res.emplace_back((res.back()-a+p-1)%(p-1));
		}
		else{
			rep(i,pa-2) res.emplace_back((res.back()+a)%(p-1));
		}
	}
	res.emplace_back((res.back()-a+p-1)%(p-1));
	rep(j,pb-1) res.emplace_back((res.back()-b+p-1)%(p-1));

	puts("Yes");
	rep(i,p) printf("%d%c",g[res[i]],i<p-1?' ':'\n');

	return 0;
}
