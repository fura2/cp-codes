#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	double ans=0;
	rep(i,n-1) ans+=n/(n-i-1.0);
	printf("%.9f\n",ans);

	return 0;
}
