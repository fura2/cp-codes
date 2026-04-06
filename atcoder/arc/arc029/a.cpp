#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=INF;
	rep(S,1<<n){
		int cost1=0,cost2=0;
		rep(i,n){
			if(S>>i&1) cost1+=a[i];
			else       cost2+=a[i];
		}
		ans=min(ans,max(cost1,cost2));
	}
	printf("%d\n",ans);

	return 0;
}
