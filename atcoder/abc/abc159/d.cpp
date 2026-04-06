#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	vector<lint> hist(n);
	rep(i,n) hist[a[i]]++;

	lint res=0;
	rep(i,n) res+=hist[i]*(hist[i]-1)/2;
	rep(i,n) printf("%lld\n",res-hist[a[i]]*(hist[a[i]]-1)/2+(hist[a[i]]-1)*(hist[a[i]]-2)/2);

	return 0;
}
