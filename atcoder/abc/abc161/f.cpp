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
	lint n; scanf("%lld",&n);

	int ans=divisors(n-1).size()-1;
	for(lint d:divisors(n)) if(d>=2) {
		lint m=n;
		while(m%d==0) m/=d;
		if(m%d==1) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
