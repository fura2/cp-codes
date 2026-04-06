#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=998244353;

int main(){
	int n;
	string s; cin>>n>>s;
	vector<int> x(n);
	rep(i,n) x[i]=s[i]-'0';

	vector<int> D; // divisors d of n s.t. n/d is odd
	for(int i=1;i*i<=n;i++) if(n%i==0) {
		D.emplace_back(i);
		if(i*i<n) D.emplace_back(n/i);
	}
	sort(D.begin(),D.end());
	rep(i,D.size()) if((n/D[i])%2==0) D.erase(D.begin()+i), i--;

	lint ans=0;
	vector<lint> num; // num[i] := number of k's with minimum period 2*d[i]
	for(int d:D){
		int m=n/d;

		// x[0..d) から始まるパターンが可能かどうか
		bool ok=true;
		for(int i=1;i<m;i++){
			int ok2=-1;
			rep(j,d){
				int k=(i%2==1?1-x[j]:x[j]);
				if     (k<x[i*d+j]){ ok2=1; break; }
				else if(k>x[i*d+j]){ ok2=0; break; }
			}
			if     (ok2==1){ ok=true;  break; }
			else if(ok2==0){ ok=false; break; }
		}

		lint cnt=0;
		rep(i,d) cnt=(cnt*2+x[i])%MOD;
		if(ok) cnt=(cnt+1)%MOD;

		rep(i,num.size()) if(d%D[i]==0) cnt=(cnt-num[i]+MOD)%MOD; // inclusion-exclusion
		num.emplace_back(cnt);
		ans=(ans+2*d*cnt)%MOD;
	}

	cout<<ans<<endl;

	return 0;
}
