#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	priority_queue<pair<int,int>> Q;
	rep(i,n){
		int a; scanf("%d",&a);
		Q.emplace(a,1);
	}
	rep(i,m){
		int b,c; scanf("%d%d",&b,&c);
		Q.emplace(c,b);
	}

	long long ans=0;
	while(n>0){
		auto x=Q.top(); Q.pop();
		int val=x.first,num=x.second;
		ans+=1LL*val*min(num,n);
		n-=min(num,n);
	}
	printf("%lld\n",ans);

	return 0;
}
