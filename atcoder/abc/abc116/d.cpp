#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	pair<int,int> a[100000];
	rep(i,n) scanf("%d%d",&a[i].second,&a[i].first), a[i].second--;

	sort(a,a+n,greater<pair<int,int>>());

	lint sum1[100001]={};
	rep(i,n) sum1[i+1]=sum1[i]+a[i].first;

	lint ans=0;
	vector<pair<int,lint>> S={{-1,0}};
	int idx=0;
	bool used[100000]={};
	for(int i=1;i<=k;i++){
		for(;idx<n;idx++){
			if(!used[a[idx].second]){
				used[a[idx].second]=true;
				S.emplace_back(idx,S.back().second+a[idx].first);
				break;
			}
		}
		if(idx==n) break;

		int lo=0,hi=k;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			int d=S.end()-upper_bound(S.begin(),S.end(),make_pair(mi,INF));
			if(mi+1+d<=k) lo=mi;
			else          hi=mi;
		}

		auto it=upper_bound(S.begin(),S.end(),make_pair(lo,INF));
		lint sum2=S.back().second-((--it)->second);

		ans=max(ans,sum1[lo+1]+sum2+1LL*i*i);
	}
	printf("%lld\n",ans);

	return 0;
}
