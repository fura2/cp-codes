#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	int a[100];
	rep(i,n) scanf("%d",&a[i]);

	int ans=INF;
	for(int tar=-100;tar<=100;tar++){
		int cost=0;
		rep(i,n) cost+=(a[i]-tar)*(a[i]-tar);
		ans=min(ans,cost);
	}
	printf("%d\n",ans);

	return 0;
}
