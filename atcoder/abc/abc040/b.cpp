#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans=n;
	for(int h=1;h<=n;h++){
		int w=n/h;
		ans=min(ans,abs(h-w)+(n-h*w));
	}
	printf("%d\n",ans);

	return 0;
}
