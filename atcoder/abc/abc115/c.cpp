#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> h(n);
	rep(i,n) scanf("%d",&h[i]);

	sort(h.begin(),h.end());

	int ans=h[n-1]-h[0];
	rep(i,n-k+1) ans=min(ans,h[i+k-1]-h[i]);
	printf("%d\n",ans);

	return 0;
}
