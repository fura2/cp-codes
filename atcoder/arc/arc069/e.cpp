#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n+1);
	rep(i,n) scanf("%lld",&a[i+1]);
	n++;

	priority_queue<pair<lint,int>> Q;
	rep(i,n) Q.emplace(a[i],-i);

	vector<lint> ans(n);
	int cnt=0;
	while(1){
		int i=-Q.top().second; Q.pop();

		if(i==0) break;

		int j;
		vector<int> I={i};
		while(1){
			j=-Q.top().second;
			if(j<i) break;
			Q.pop();
			I.emplace_back(j);
		}

		ans[i]+=(a[i]-a[j])*cnt;
		for(int k:I){
			ans[i]+=a[k]-a[j];
		}
		cnt+=I.size();
	}

	rep(i,n-1) printf("%lld\n",ans[i+1]);

	return 0;
}
