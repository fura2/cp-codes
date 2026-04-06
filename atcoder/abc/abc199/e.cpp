#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> p[19];
	rep(i,m){
		int x,y,z; scanf("%d%d%d",&x,&y,&z); y--;
		p[x].emplace_back(y,z);
	}

	bool good[1<<18]={};
	rep(S,1<<n){
		int cum[19]={};
		rep(i,n) if(S>>i&1) cum[i+1]++;
		rep(i,n) cum[i+1]+=cum[i];

		good[S]=true;
		int x=popcount(S);
		for(auto [y,z]:p[x]){
			if(cum[y+1]>z) good[S]=false;
		}
	}

	lint dp[1<<18]={};
	dp[0]=1;
	rep(S,1<<n){
		rep(i,n) if(~S>>i&1) {
			int S2=S|(1<<i);
			if(good[S2]){
				dp[S2]+=dp[S];
			}
		}
	}
	printf("%lld\n",dp[(1<<n)-1]);

	return 0;
}
