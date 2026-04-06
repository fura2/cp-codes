#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint tar;
map<lint,lint> memo;

lint dfs(lint cur){
	if(cur<=tar){
		return tar-cur;
	}

	if(memo.count(cur)!=0){
		return memo[cur];
	}

	lint res=cur-tar;
	if(cur%2==0){
		res=min(res,dfs(cur/2)+1);
	}
	else{
		res=min(res,dfs(cur/2)+2);
		res=min(res,dfs(cur/2+1)+2);
	}
	return memo[cur]=res;
}

int main(){
	lint x,y; scanf("%lld%lld",&x,&y);

	tar=x;
	printf("%lld\n",dfs(y));

	return 0;
}
