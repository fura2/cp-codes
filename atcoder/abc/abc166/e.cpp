#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=0;
	map<int,int> L;
	rep(i,n){
		ans+=L[i-a[i]];
		++L[i+a[i]];
	}
	printf("%lld\n",ans);

	return 0;
}
