#include <algorithm>
#include <cstdio>
#include <set>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int p[100000];
	rep(i,n) scanf("%d",p+i), p[i]--;

	int f[100000];
	rep(i,n) f[p[i]]=i;

	set<int> S={f[n-1],-2,-1,n,n+1};

	long long ans=0;
	for(int i=n-2;i>=0;i--){
		auto it=S.upper_bound(f[i]);
		int c=*it;
		++it;
		int d=*it;
		--it; --it;
		int b=*it;
		--it;
		int a=*it;

		a=max(a,-1);
		b=max(b,-1);
		c=min(c,n);
		d=min(d,n);

		if(c< n) ans+=(i+1LL)*(f[i]-b)*(d-c);
		if(b>=0) ans+=(i+1LL)*(b-a)*(c-f[i]);

		S.insert(f[i]);
	}
	printf("%lld\n",ans);

	return 0;
}
