#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> ans(n);
	for(int u=1;u<n;u++){
		int p; scanf("%d",&p); p--;
		ans[p]++;
	}
	rep(u,n) printf("%d\n",ans[u]);
	return 0;
}
