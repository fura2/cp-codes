#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,m) scanf("%d",&b[j]);

	sort(b.begin(),b.end());

	int ans=INT_MAX;
	rep(i,n){
		int j=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		if(j<m) ans=min(ans,abs(a[i]-b[j]));
		if(j>0) ans=min(ans,abs(a[i]-b[j-1]));
	}
	printf("%d\n",ans);

	return 0;
}
