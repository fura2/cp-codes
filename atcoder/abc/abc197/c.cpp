#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[20];

int dfs(int i,int sum,int cur){
	if(i==n) return sum^cur;
	return min(dfs(i+1,sum^(cur|a[i]),0),dfs(i+1,sum,cur|a[i]));
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	printf("%d\n",dfs(0,0,0));
	return 0;
}
