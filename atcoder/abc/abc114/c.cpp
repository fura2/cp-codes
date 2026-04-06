#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

long long n;

int dfs(long long d,bool a,bool b,bool c){
	if(d>n) return 0;
	int res=(a&&b&&c?1:0);
	res+=dfs(10*d+3,true,b,c);
	res+=dfs(10*d+5,a,true,c);
	res+=dfs(10*d+7,a,b,true);
	return res;
}

int main(){
	scanf("%lld",&n);
	printf("%d\n",dfs(0,false,false,false));
	return 0;
}
