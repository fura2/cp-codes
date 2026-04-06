#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	int ans=0;
	rep(i,n) for(int j=i+1;j<n;j++) {
		if(abs(x[i]-x[j])>=abs(y[i]-y[j])) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
