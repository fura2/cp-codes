#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=INF;
	rep(x,101){
		int sum=0;
		rep(i,n) sum+=(x-a[i])*(x-a[i]);
		ans=min(ans,sum);
	}
	printf("%d\n",ans);

	return 0;
}
