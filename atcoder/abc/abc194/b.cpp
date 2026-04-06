#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	int ans=INF;
	rep(i,n) ans=min(ans,a[i]+b[i]);
	rep(i,n) rep(j,n) if(i!=j) ans=min(ans,max(a[i],b[j]));
	printf("%d\n",ans);

	return 0;
}
