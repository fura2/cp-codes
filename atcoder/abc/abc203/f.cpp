#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,to[200001];
int memo[200001][31];

int dfs(int i,int j){
	int& res=memo[i][j];
	if(res!=-1) return res;

	if(i==n) return res=0;

	res=dfs(i+1,j)+1;
	if(j>0) res=min(res,dfs(to[i],j-1));
	return res;
}

int main(){
	int k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.rbegin(),a.rend());
	int r=0;
	rep(l,n){
		while(r<n && a[l]<2*a[r]) r++;
		to[l]=r;
	}

	memset(memo,-1,sizeof memo);

	int ans=30;
	rep(j,31) if(dfs(0,j)<=k) {
		ans=j;
		break;
	}
	printf("%d %d\n",ans,dfs(0,ans));

	return 0;
}
