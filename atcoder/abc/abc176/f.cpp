#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(3*n);
	rep(i,3*n) scanf("%d",&a[i]), a[i]--;

	int cnt=0;
	vector dp(n,vector(n,-INF));
	vector dp_max1(n,-INF); // dp_max1[x] = max_y dp[x][y]
	int dp_max2=-INF;       // dp_max2 = max_{x,y} dp[x][y]

	auto update=[&](int x,int y,int val){
		dp[x][y]=max(dp[x][y],val);
		dp[y][x]=max(dp[y][x],val);
		dp_max1[x]=max(dp_max1[x],dp[x][y]);
		dp_max1[y]=max(dp_max1[y],dp[y][x]);
		dp_max2=max(dp_max2,dp[x][y]);
	};

	update(a[0],a[1],0);
	for(int i=2;i<3*n-2;i+=3){
		int x=a[i],y=a[i+1],z=a[i+2];

		// 前回残した二つを残す
		if(x==y && x==z){
			cnt++;
			continue;
		}

		vector<tuple<int,int,int>> next;
		// x, y を残す
		next.emplace_back(x,y,max(dp_max2,dp[z][z]+1));
		// y, z を残す
		next.emplace_back(y,z,max(dp_max2,dp[x][x]+1));
		// z, x を残す
		next.emplace_back(z,x,max(dp_max2,dp[y][y]+1));
		rep(w,n){
			// 前回残した一つと x を残す
			next.emplace_back(w,x,dp_max1[w]);
			if(y==z) next.emplace_back(w,x,dp[w][y]+1);
			// 前回残した一つと y を残す
			next.emplace_back(w,y,dp_max1[w]);
			if(z==x) next.emplace_back(w,y,dp[w][z]+1);
			// 前回残した一つと z を残す
			next.emplace_back(w,z,dp_max1[w]);
			if(x==y) next.emplace_back(w,z,dp[w][x]+1);
		}

		for(auto [x,y,val]:next) update(x,y,val);
	}

	printf("%d\n",max(dp_max2,dp[a[3*n-1]][a[3*n-1]]+1)+cnt);

	return 0;
}
