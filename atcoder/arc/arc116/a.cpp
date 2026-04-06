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

void solve(){
	lint n; scanf("%lld",&n);
	puts(n%2==1?"Odd":n%4==2?"Same":"Even");
}

int main(){
/*
	for(int t=1;t<=50;t++){
		int cnt[2]={};
		for(lint d:divisors(t)) cnt[d%2]++;
		printf("%2d: %s\n",t,cnt[0]==cnt[1]?"same":cnt[0]>cnt[1]?"even":"odd");
	}
*/

	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
