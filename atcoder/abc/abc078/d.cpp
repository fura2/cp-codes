#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[2001];
int memo1[2001],memo2[2001];

int dfs2(int);

int dfs1(int i){
	if(~memo1[i]) return memo1[i];

	int res=abs(a[n-1]-a[i-1]);
	for(int j=i;j<n-1;j++) res=max(res,dfs2(j+1));
	return memo1[i]=res;
}

int dfs2(int i){
	if(~memo2[i]) return memo2[i];

	int res=abs(a[n-1]-a[i-1]);
	for(int j=i;j<n-1;j++) res=min(res,dfs1(j+1));
	return memo2[i]=res;
}

int main(){
	int dummy; scanf("%d%*d%d",&n,a);
	rep(i,n) scanf("%d",a+i+1);
	n++;

	memset(memo1,-1,sizeof memo1);
	memset(memo2,-1,sizeof memo2);

	cout<<dfs1(1)<<endl;

	return 0;
}
