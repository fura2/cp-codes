#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=0;
	for(int D=1;D<n;D++){
		// sum1 = a[0]+a[D]+a[2D]+...+a[KD]
		// sum2 = a[A]+a[A+D]+a[A+2D]+...+a[A+KD]
		lint sum1=0,sum2=0;

		for(int k=1;;k++){
			int A=n-k*D-1;
			if(A<D) break;

			sum1+=a[k*D];
			sum2+=a[A];

			if(A%D==0 && A/D<=k) continue;

			ans=max(ans,sum1+sum2);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
