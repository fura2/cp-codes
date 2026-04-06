#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	bool neg=true;
	rep(i,n) if(a[i]>=0) neg=false;
	if(neg){
		int i0=max_element(a.begin(),a.end())-a.begin();
		printf("%lld\n%d\n",a[i0],n-1);
		rep(i,n-i0-1) printf("%d\n",n-i);
		rep(i,i0) puts("1");
		return 0;
	}

	vector dp(n+2,-INF);
	vector dp_max(n+2,-INF);
	rep(i,2) dp[i]=dp_max[i]=0;
	rep(p,2) rep(i,n) {
		if(i%2==p){
			dp[i+2]=a[i]+max(dp_max[i],0LL);
			dp_max[i+2]=max(dp[i+2],dp_max[i]);
		}
	}

	lint mx=max(dp_max[n],dp_max[n+1]);
	int p_max=-1;
	rep(i,n) if(dp[i+2]==mx) p_max=i%2;
	assert(p_max!=-1);

	deque<bool> D(n);
	{
		lint tmp=mx;
		for(int i=n-1;i>=0;i--) if(i%2==p_max) {
			if(dp[i+2]==tmp){
				D[i]=true;
				tmp-=a[i];
			}
		}
	}

	vector<int> ans;
	while(D.size()>1){
		if(!D.front()){ // x??...?
			ans.emplace_back(0);
			D.pop_front();
		}
		else if(!D.back()){ // ??...?x
			ans.emplace_back(D.size()-1);
			D.pop_back();
		}
		else{ // ??...?xo
			assert(D.size()>=3);
			if(D[D.size()-3]){ // ??...?oxo
				ans.emplace_back(D.size()-2);
				D.pop_back();
				D.pop_back();
			}
			else{ // ??...?xxxo
				assert(D.size()>=4 && !D[D.size()-4]);
				ans.emplace_back(D.size()-3);
				D.erase(prev(D.end(),2));
				D.erase(prev(D.end(),2));
			}
		}
	}

	printf("%lld\n%ld\n",mx,ans.size());
	rep(i,ans.size()) printf("%d\n",ans[i]+1);

	return 0;
}
