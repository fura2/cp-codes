#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int d[8][8];
	rep(u,n) rep(v,n) scanf("%d",&d[u][v]);

	int p[8];
	iota(p,p+n,0);

	int ans=0;
	do{
		int tmp=0;
		rep(i,n) tmp+=d[p[i]][p[(i+1)%n]];
		if(tmp==k) ans++;
	}while(next_permutation(p+1,p+n));
	printf("%d\n",ans);

	return 0;
}
