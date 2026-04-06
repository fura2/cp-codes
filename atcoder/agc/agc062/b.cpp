#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using lint=long long;

const long long INF=1LL<<61;

int m;
vector<lint> cost;
vector<lint> A,cum;

lint memo[101][101][101];
lint dfs(int l,int r,int k){
	if(r-l==1) return 0;
	if(k==m) return INF;

	if(~memo[l][r][k]) return memo[l][r][k];

	lint res=dfs(l,r,k+1);
	for(int m=l+1;m<r;m++){
		res=min(res,dfs(l,m,k+1)+dfs(m,r,k+1)+cost[k]*(cum[r]-cum[m]));
	}
	return memo[l][r][k]=res;
}

int main(){
	memset(memo,-1,sizeof memo);

	int n; cin>>n>>m;
	cost.resize(m);
	vector<int> a(n);
	rep(i,m) cin>>cost[i];
	rep(i,n) cin>>a[i], a[i]--;

	for(int x=0;x<n;){
		int cnt=0;
		rep(i,n) if(a[i]==x) {
			cnt++;
			x++;
		}
		A.emplace_back(cnt);
	}

	cum.emplace_back(0);
	rep(i,A.size()) cum.emplace_back(cum.back()+A[i]);

	lint ans=dfs(0,A.size(),0);
	cout<<(ans<INF?ans:-1)<<'\n';

	return 0;
}
