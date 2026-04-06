#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	rep(l,n){
		int mn=INF;
		for(int r=l;r<n;r++){
			mn=min(mn,a[r]);
			ans=max(ans,mn*(r-l+1));
		}
	}
	printf("%d\n",ans);

	return 0;
}
