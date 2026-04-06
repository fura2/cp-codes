#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,W; scanf("%d%d",&n,&W);
	vector<int> w(n); rep(i,n) scanf("%d",&w[i]);

	vector<int> S1,S2;
	rep(S,1<<n/2){
		int sum=0;
		rep(i,n/2) if(S>>i&1) sum+=w[i];
		S1.emplace_back(sum);
	}
	rep(S,1<<(n+1)/2){
		int sum=0;
		rep(i,(n+1)/2) if(S>>i&1) sum+=w[n-i-1];
		S2.emplace_back(sum);
	}

	sort(S2.begin(),S2.end());

	lint ans=0;
	for(int sum:S1){
		auto p=equal_range(S2.begin(),S2.end(),W-sum);
		ans+=p.second-p.first;
	}
	printf("%lld\n",ans);

	return 0;
}
