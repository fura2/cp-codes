#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	vector<int> a(n+1);
	iota(a.begin(),a.end(),0);

	int pre=0;
	rep(i,m){
		int d; scanf("%d",&d);
		swap(a[pre],a[d]);
		pre=d;
	}

	vector<int> ans(n+1);
	rep(i,n+1) ans[a[i]]=i;
	rep(i,n) printf("%d\n",ans[i+1]);

	return 0;
}
