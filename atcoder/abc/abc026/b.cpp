#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	int n; scanf("%d",&n);
	int r[1001]={};
	rep(i,n) scanf("%d",&r[i+1]);

	sort(r,r+n+1);

	double ans=0;
	for(int i=n;i>0;i-=2) ans+=PI*(r[i]*r[i]-r[i-1]*r[i-1]);
	printf("%.9f\n",ans);

	return 0;
}
