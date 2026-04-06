#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);
	vector<int> to(n);
	rep(u,n) scanf("%d",&to[u]), to[u]--;

	static int dbl[60][200000];
	rep(u,n) dbl[0][u]=to[u];
	rep(t,59) rep(u,n) dbl[t+1][u]=dbl[t][dbl[t][u]];

	int pos=0;
	rep(t,60) if(k>>t&1) pos=dbl[t][pos];
	printf("%d\n",pos+1);

	return 0;
}
