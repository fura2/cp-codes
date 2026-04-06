#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n,a[500];
int memo[500][501];

int dfs(int l,int r){
	if(l==r) return 0;

	int& res=memo[l][r];
	if(res!=-INF) return res;

	res=0;
	for(int x=l+1;x<r;x++){
		int tmp1=dfs(l,x);
		int tmp2=dfs(x,r);
		if(tmp1!=-INF && tmp2!=-INF){
			res=max(res,tmp1+tmp2);
		}
	}
	if((l+2)%3==(r-1)%3){
		for(int x=l+1;x<r-1;x+=3){
			int tmp1=dfs(l+1,x);
			int tmp2=dfs(x+1,r-1);
			if(tmp1!=-INF && tmp2!=-INF){
				res=max(res,a[l]+a[x]+a[r-1]+tmp1+tmp2);
			}
		}
	}
	return res;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	rep(l,n) rep(r,n+1) memo[l][r]=-INF;
	printf("%d\n",dfs(0,n));

	return 0;
}
