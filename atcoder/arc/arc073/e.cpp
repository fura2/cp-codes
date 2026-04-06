#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> a(n);
	rep(i,n){
		int l,r; scanf("%d%d",&l,&r);
		a[i]=minmax(l,r);
	}

	int mx=0,mn=1e9;
	rep(i,n){
		mx=max(mx,a[i].second);
		mn=min(mn,a[i].first);
	}

	lint ans=1LL<<61;
	{
		int rmx=mn,bmn=mx;
		rep(i,n){
			rmx=max(rmx,a[i].first);
			bmn=min(bmn,a[i].second);
		}
		ans=min(ans,1LL*(rmx-mn)*(mx-bmn));
	}
	{
		sort(a.begin(),a.end());
		multiset<int> S;
		rep(i,n) S.emplace(a[i].first);
		rep(i,n+1){
			int bmn=*S.begin(),bmx=*S.rbegin();
			ans=min(ans,1LL*(mx-mn)*(bmx-bmn));
			if(i<n){
				S.erase(S.find(a[i].first));
				S.emplace(a[i].second);
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}
