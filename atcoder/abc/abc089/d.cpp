#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,d; scanf("%d%d%d",&h,&w,&d);
	int a[300][300];
	rep(i,h) rep(j,w) scanf("%d",a[i]+j), a[i][j]--;

	pair<int,int> pos[300*300];
	rep(i,h) rep(j,w) pos[a[i][j]]={i,j};

	vector<int> sum[300*300];
	rep(i,d){
		sum[i].emplace_back(0);
		for(int x=i+d;x<h*w;x+=d){
			sum[i].emplace_back(sum[i].back()+abs(pos[x].first-pos[x-d].first)+abs(pos[x].second-pos[x-d].second));
		}
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int l,r; scanf("%d%d",&l,&r); l--; r--;
		printf("%d\n",sum[l%d][r/d]-sum[l%d][l/d]);
	}

	return 0;
}
