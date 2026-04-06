#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int r=0;
	long long ans=0,s=0,x=0;
	rep(l,n){
		while(r<n && s+a[r]==(x^a[r])){
			s+=a[r];
			x^=a[r];
			r++;
		}
		s-=a[l];
		x^=a[l];
		ans+=r-l;
	}
	printf("%lld\n",ans);

	return 0;
}
