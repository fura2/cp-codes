#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m+2);
	rep(i,m) scanf("%d",&a[i]);
	a[m]=0; a[m+1]=n+1;
	sort(a.begin(),a.end());

	int mn=n;
	rep(i,m+1) if(a[i+1]-a[i]>=2) mn=min(mn,a[i+1]-a[i]-1);

	int ans=0;
	rep(i,m+1) if(a[i+1]-a[i]>=2) ans+=(a[i+1]-a[i]-1+mn-1)/mn;
	printf("%d\n",ans);

	return 0;
}
