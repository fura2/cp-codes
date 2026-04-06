#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<long long> divisors(long long a){
	vector<long long> res;
	for(long long i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	set<int> D;
	rep(i,n) for(auto d:divisors(a[i])) D.emplace(d);

	int ans=0;
	for(int d:D){
		int g=0;
		rep(i,n) if(a[i]%d==0) g=gcd(g,a[i]);
		if(g!=d) continue;

		bool ok=true;
		rep(i,n) if(a[i]%d!=0 && a[i]<d) ok=false;
		if(ok) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
