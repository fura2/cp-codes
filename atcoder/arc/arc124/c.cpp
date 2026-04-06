#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n;
lint a[1000],b[1000];

map<pair<lint,lint>,lint> memo[51];

lint dfs(int i,lint x,lint y){
	if(memo[i].count({x,y})>0) return memo[i][{x,y}];
	lint& res=memo[i][{x,y}];

	if(i==n){
		return memo[i][{x,y}]=lcm(x,y);
	}
	return memo[i][{x,y}]=max(dfs(i+1,gcd(x,a[i]),gcd(y,b[i])),dfs(i+1,gcd(x,b[i]),gcd(y,a[i])));
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%lld%lld",&a[i],&b[i]);

	printf("%lld\n",dfs(1,a[0],b[0]));

	return 0;
}
