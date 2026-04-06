#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld%lld",&a[i],&b[i]);

	lint sum=-accumulate(a.begin(),a.end(),0LL);

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return 2*a[i]+b[i]>2*a[j]+b[j];
	});

	rep(i,n+1){
		if(sum>0){
			printf("%d\n",i);
			break;
		}
		if(i<n) sum+=2*a[p[i]]+b[p[i]];
	}

	return 0;
}
