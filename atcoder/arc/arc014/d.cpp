#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int all,n,q; scanf("%d%d%d",&all,&n,&q);
	vector<int> L(n); rep(i,n) scanf("%d",&L[i]), L[i]--;

	vector<int> d(n-1);
	rep(i,n-1) d[i]=L[i+1]-L[i]-1;
	sort(d.begin(),d.end());

	vector<lint> sum(n);
	rep(i,n-1) sum[i+1]=sum[i]+d[i];

	rep(_,q){
		int x,y; scanf("%d%d",&x,&y);
		lint cnt=0;
		cnt+=max(L[0]-x,0);
		cnt+=max(all-(L[n-1]+y)-1,0);
		int idx=upper_bound(d.begin(),d.end(),x+y)-d.begin();
		cnt+=sum[n-1]-sum[idx]-1LL*(n-idx-1)*(x+y);
		printf("%lld\n",all-cnt);
	}

	return 0;
}
