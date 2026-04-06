#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n;
lint r[49],b[50];

lint memo[50][2];

lint dfs(int i,int carry){
	lint& res=memo[i][carry];
	if(res!=-1) return res;

	if(i==n-1) return res=1;

	res=0;
	if(b[i]+carry==r[i]){
		// お釣りに a[i] 円玉が含まれない
		res+=dfs(i+1,1);
	}
	else if(b[i]+carry==0){
		// お釣りに a[i] 円玉が含まれない
		res+=dfs(i+1,0);
	}
	else{
		// お釣りに a[i] 円玉が含まれない
		res+=dfs(i+1,0);
		// お釣りに a[i] 円玉が含まれる
		res+=dfs(i+1,1);
	}
	return res;
}

int main(){
	lint x,a[50]; scanf("%d%lld",&n,&x);
	rep(i,n) scanf("%lld",&a[i]);

	rep(i,n-1) r[i]=a[i+1]/a[i];

	for(int i=n-1;i>=0;i--){
		b[i]=x/a[i];
		x%=a[i];
	}

	memset(memo,-1,sizeof memo);
	printf("%lld\n",dfs(0,0));

	return 0;
}
