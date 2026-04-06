#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1e9+7;
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w; scanf("%d%d",&h,&w);

	int a[1000][1000];
	vector<tuple<int,int,int>> V;
	rep(i,h) rep(j,w) {
		scanf("%d",a[i]+j);
		V.emplace_back(a[i][j],i,j);
	}

	sort(V.rbegin(),V.rend());

	int dp[1000][1000];
	for(auto v:V){
		int i=get<1>(v),j=get<2>(v);
		dp[i][j]=1;
		rep(k,4){
			int y=i+dy[k],x=j+dx[k];
			if(0<=y && y<h && 0<=x && x<w && a[i][j]<a[y][x]) dp[i][j]=(dp[i][j]+dp[y][x])%MOD;
		}
	}

	int ans=0;
	rep(i,h) rep(j,w) ans=(ans+dp[i][j])%MOD;
	printf("%d\n",ans);

	return 0;
}
