#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int>> a(n,vector<int>(m));
	rep(i,n) rep(j,m) scanf("%d",&a[i][j]), a[i][j]--;

	int ans=n;
	while(!a[0].empty()){
		int cnt[300]={};
		rep(i,n) cnt[a[i][0]]++;

		int mx=*max_element(cnt,cnt+m);
		ans=min(ans,mx);

		rep(i,n){
			rep(j,a[i].size()) if(cnt[a[i][j]]==mx) {
				a[i].erase(a[i].begin()+j);
				j--;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
