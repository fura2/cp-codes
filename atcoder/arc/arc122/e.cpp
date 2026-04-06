#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

bool Miller_Rabin(lint n){
	if(n<=1)   return false;
	if(n%2==0) return n==2;

	auto modpow=[](lint a,lint k,lint m){
		lint r=1;
		for(lint x=a;k>0;k>>=1){
			if(k&1) r=__int128(r)*x%m;
			x=__int128(x)*x%m;
		}
		return r;
	};

	int r=0;
	lint d=n-1;
	while(d%2==0) r++, d>>=1;

	for(lint a:{2,3,5,7,11,13,17,19,23,29,31,37}){
		if(a>=n-2) break;
		lint x=modpow(a,d,n);
		if(x==1 || x==n-1) continue;
		bool b=false;
		rep(_,r-1){
			x=__int128(x)*x%n;
			if(x==n-1){
				b=true;
				break;
			}
		}
		if(!b) return false;
	}
	return true;
}

map<lint,int> Pollard_rho(lint n){
	map<lint,int> pf;
	if(n<=1) return pf;
	if(Miller_Rabin(n)){ ++pf[n]; return pf; }

	auto divisor=[](lint n,int c)->lint{
		if(n%2==0) return 2;

		lint x=2,y=2,d=1;
		while(d==1){
			x=__int128(x)*x%n+c; if(x<0) x+=n;
			y=__int128(y)*y%n+c; if(y<0) y+=n;
			y=__int128(y)*y%n+c; if(y<0) y+=n;
			d=gcd(abs(x-y),n);
		}
		return d<n?d:-1;
	};

	lint d=-1;
	for(int c=1;d==-1;c++) d=divisor(n,c);

	for(auto [p,e]:Pollard_rho( d )) pf[p]+=e;
	for(auto [p,e]:Pollard_rho(n/d)) pf[p]+=e;
	return pf;
}

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<map<lint,int>> pf(n);
	map<lint,set<pair<int,int>>> P; // prime number -> {(exponent, index)}
	rep(i,n){
		pf[i]=Pollard_rho(a[i]);
		for(auto [p,e]:pf[i]){
			P[p].emplace(e,i);
		}
	}

	vector<bool> used(n);
	queue<int> Q;
	for(auto& [p,S]:P){
		if(S.empty()) continue;

		auto [e,i]=*prev(S.end());
		bool ok=!used[i];
		if(S.size()>=2){
			auto [e2,i2]=*prev(prev(S.end()));
			if(e2==e) ok=false;
		}
		if(ok){
			used[i]=true;
			Q.emplace(i);
			for(const auto& [q,f]:pf[i]) P[q].erase({f,i});
		}
	}

	vector<int> res;
	while(!Q.empty()){
		int i=Q.front(); Q.pop();

		res.emplace_back(i);

		for(const auto& [p,_]:pf[i]){
			auto& S=P[p];
			if(S.empty()) continue;

			auto [e,i]=*prev(S.end());
			bool ok=!used[i];
			if(S.size()>=2){
				auto [e2,i2]=*prev(prev(S.end()));
				if(e2==e) ok=false;
			}
			if(ok){
				used[i]=true;
				Q.emplace(i);
				for(const auto& [q,f]:pf[i]) P[q].erase({f,i});
			}
		}
	}

	if(res.size()<n){
		puts("No");
	}
	else{
		puts("Yes");
		rep(i,n) printf("%lld%c",a[res[n-i-1]],i<n-1?' ':'\n');
	}

	return 0;
}
