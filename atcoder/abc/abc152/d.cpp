#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	lint cnt[10][10]={};
	for(int x=1;x<=n;x++){
		cnt[to_string(x)[0]-'0'][x%10]++;
	}

	lint ans=0;
	rep(i,10) rep(j,10) ans+=cnt[i][j]*cnt[j][i];
	printf("%lld\n",ans);

	return 0;
}
