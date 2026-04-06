#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> S,T;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		if(a-b<=0) S.emplace_back(a,b);
		else       T.emplace_back(a,b);
	}

	sort(S.begin(),S.end());
	sort(T.begin(),T.end(),[](const pair<int,int>& p,const pair<int,int>& q){
		return max(p.first,p.first-p.second+q.first)<max(q.first,q.first-q.second+p.first);
	});

	lint ans=0,now=0;
	for(auto p:S){
		now+=p.first; ans=max(ans,now);
		now-=p.second;
	}
	for(auto p:T){
		now+=p.first; ans=max(ans,now);
		now-=p.second;
	}
	printf("%lld\n",ans);

	return 0;
}
