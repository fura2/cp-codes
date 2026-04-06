#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint sum=0;
	rep(i,n) sum+=a[i];
	if(sum%(n*(n+1)/2)!=0) return puts("NO"),0;

	lint m=sum/(n*(n+1)/2),cnt=0;
	rep(i,n){
		lint d=a[(i+1)%n]-a[i];
		if(m-d<0 || (m-d)%n!=0) return puts("NO"),0;
		cnt+=(m-d)/n;
	}
	puts(cnt==m?"YES":"NO");

	return 0;
}
