#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int n;
lint a[100];

int k;
lint memo[101][101][100];

// a[i,n) から j 個選んで, 選んだ a の和 mod k が m であるときの, 選んだ a の和の最大値
lint dfs(int i,int j,int m){
	lint& res=memo[i][j][m];
	if(res!=-1) return res;

	if(i==n){
		if(j==0 && m==0) return res=0;
		else             return res=-INF;
	}

	// a[i] を選ばない
	res=dfs(i+1,j,m);
	// a[i] を選ぶ
	if(j>0){
		int m2=(m-a[i])%k;
		if(m2<0) m2+=k;
		lint tmp=dfs(i+1,j-1,m2);
		if(tmp>=0) res=max(res,tmp+a[i]);
	}
	return res;
}

int main(){
	lint x; scanf("%d%lld",&n,&x);
	rep(i,n) scanf("%lld",&a[i]);

	lint ans=INF;
	for(k=1;k<=n;k++){
		memset(memo,-1,sizeof memo);
		lint res=dfs(0,k,x%k);
		if(res>=0) ans=min(ans,(x-res)/k);
	}
	printf("%lld\n",ans);

	return 0;
}
