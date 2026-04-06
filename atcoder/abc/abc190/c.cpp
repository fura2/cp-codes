#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m),b(m);
	rep(i,m) scanf("%d%d",&a[i],&b[i]), a[i]--, b[i]--;

	int k; scanf("%d",&k);
	vector<int> c(k),d(k);
	rep(i,k) scanf("%d%d",&c[i],&d[i]), c[i]--, d[i]--;

	int ans=0;
	rep(S,1<<k){
		bool f[100]={};
		rep(i,k) f[S>>i&1?c[i]:d[i]]=true;

		int cnt=0;
		rep(i,m) if(f[a[i]] && f[b[i]]) cnt++;
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}
