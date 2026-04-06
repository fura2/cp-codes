// 初めて解いたときのコード
/*
	first part of this solution is based on
	https://maspypy.com/atcoder-%e5%8f%82%e5%8a%a0%e6%84%9f%e6%83%b3-2019-09-21agc-038

	Let f(d) := Sum_{i<j, gcd(a_i,a_j)=d} a_i*a_j.
	The answer is Sum_{d=1}^{10^6} f(d)/d.
	We use the inclusion-exclusion principle to compute f(d):
		Let g(d) := Sum_{i<j, d|a_i, d|a_j} a_i*a_j.
		Then f(d) = g(d) - Sum_{d|e, e>d} f(e). (so called 約数系包除)
		g(d) can be computed by
			(Sum_{d|a_i} a_i)^2 - Sum_{d|a_i} (a_i^2) = 2*g(d).
*/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=998244353;

lint xgcd(lint a,lint b,lint &x,lint &y){
	if(b==0){ x=1; y=0; return a; }
	lint g=xgcd(b,a%b,y,x); y-=a/b*x;
	return g;
}

lint modinv(lint a,lint m){
	lint x,y;
	if(xgcd(a,m,x,y)==1) return (x+m)%m;
	return -1;
}

// enumerate all divisors
void dfs(int i,int x,const vector<pair<int,int>> &pf,vector<int> &D){
	if(i==pf.size()){
		D.emplace_back(x);
		return;
	}
	rep(j,pf[i].second+1){ dfs(i+1,x,pf,D); x*=pf[i].first; }
}

int main(){
	vector<lint> inv(1e6+1);
	for(int i=1;i<=1e6;i++) inv[i]=modinv(i,MOD);

	vector<int> pf_min(1e6); // pf_min[i] := minimum prime factor of i
	for(int i=2;i*i<=1e6;i++) if(pf_min[i]==0) {
		for(int j=i*i;j<=1e6;j+=i) if(pf_min[j]==0) pf_min[j]=i;
	}
	for(int i=2;i<=1e6;i++) if(pf_min[i]==0) pf_min[i]=i;

	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<lint> asum(1e6+1),asum2(1e6+1);
	rep(i,n){
		int x=a[i];
		vector<pair<int,int>> pf;
		while(x>1){
			int q=pf_min[x];
			int e=0;
			do{
				x/=q;
				e++;
			}while(x%q==0);
			pf.emplace_back(q,e);
		}

		vector<int> D;
		dfs(0,1,pf,D);
		for(int d:D){
			asum[d]=(asum[d]+a[i])%MOD;
			asum2[d]=(asum2[d]+1LL*a[i]*a[i])%MOD;
		}
	}

	vector<lint> g(1e6+1);
	for(int d=1;d<=1e6;d++) g[d]=(asum[d]*asum[d]-asum2[d]+MOD)%MOD*inv[2]%MOD;

	vector<lint> f(1e6+1);
	for(int d=1e6;d>0;d--){
		f[d]=g[d];
		for(int e=2*d;e<=1e6;e+=d) f[d]=(f[d]-f[e]+MOD)%MOD;
	}

	lint ans=0;
	for(int d=1;d<=1e6;d++) ans=(ans+f[d]*inv[d])%MOD;
	printf("%lld\n",ans);

	return 0;
}
