#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d",&b[i]);

	int ans=0;
	int l=0,r=0,sum=0;
	while(l<n && sum+a[l]<=k){
		sum+=a[l];
		l++;
	}
	for(;l>=0;l--){
		while(r<m && sum+b[r]<=k){
			sum+=b[r];
			r++;
		}
		ans=max(ans,l+r);
		sum-=a[l-1];
	}
	printf("%d\n",ans);

	return 0;
}
