#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	map<int,int> f;
	rep(i,k-1) ++f[a[i]];

	int ans=0;
	for(int i=k-1;i<n;i++){
		++f[a[i]];
		ans=max<int>(ans,f.size());
		if(--f[a[i-k+1]]==0) f.erase(a[i-k+1]);
	}
	printf("%d\n",ans);

	return 0;
}
