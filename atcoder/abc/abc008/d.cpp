#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,x[30],y[30];

map<tuple<int,int,int,int>,int> memo;

int dfs(int t,int l,int b,int r){
	auto q=make_tuple(t,l,b,r);
	if(memo.count(q)>0) return memo[q];

	int res=0;
	rep(i,n) if(t<=y[i] && y[i]<b && l<=x[i] && x[i]<r) {
		res=max(res,dfs(t,l,y[i],x[i])
				   +dfs(t,x[i]+1,y[i],r)
				   +dfs(y[i]+1,l,b,x[i])
				   +dfs(y[i]+1,x[i]+1,b,r)
				   +(b-t)+(r-l)-1);
	}
	return memo[q]=res;
}

int main(){
	int w,h; scanf("%d%d%d",&w,&h,&n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]), x[i]--, y[i]--;

	printf("%d\n",dfs(0,0,h,w));

	return 0;
}
