#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> r(n),h(n);
	rep(i,n) scanf("%d%d",&r[i],&h[i]), r[i]--, h[i]--;

	int cnt[100000][3]={};
	rep(i,n) cnt[r[i]][h[i]]++;

	int sum[100001]={};
	rep(i,100000) sum[i+1]+=sum[i]+cnt[i][0]+cnt[i][1]+cnt[i][2];

	rep(i,n){
		int win=sum[r[i]]+cnt[r[i]][(h[i]+1)%3];
		int lose=sum[100000]-sum[r[i]+1]+cnt[r[i]][(h[i]+2)%3];
		printf("%d %d %d\n",win,lose,n-win-lose-1);
	}

	return 0;
}
