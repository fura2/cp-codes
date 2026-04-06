#include <algorithm>
#include <cstdio>
#include <set>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const long long INF=1LL<<61;

int main(){
	int n,a[200000];
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);

	set<long long> L,R;
	L.emplace(a[0]);
	L.emplace(a[0]+a[1]);
	{
		long long sum=0;
		rep(i,n-2) sum+=a[n-i-1], R.emplace(sum);
	}

	long long ans=INF;
	for(int i=2;i<n-1;i++){
		long long lmx=*L.rbegin();
		long long rmx=*R.rbegin();

		auto lit=L.lower_bound(lmx/2);
		rep(_,2){
			auto rit=R.lower_bound(rmx/2);
			rep(__,2){
				long long p=*lit,q=lmx-*lit,r=rmx-*rit,s=*rit;
				if(q>0 && r>0){
					ans=min(ans,max({p,q,r,s})-min({p,q,r,s}));
				}
				if(rit==R.begin()) break;
				--rit;
			}
			if(lit==L.begin()) break;
			--lit;
		}

		L.emplace(lmx+a[i]);
		R.erase(rmx);
	}
	printf("%lld\n",ans);

	return 0;
}
