#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h; scanf("%d%d",&n,&h);

	priority_queue<pair<int,int>> Q;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		Q.emplace(a,0);
		Q.emplace(b,1);
	}

	int ans=0;
	while(h>0){
		auto x=Q.top();
		if(x.second==0){
			ans+=(h+x.first-1)/x.first;
			h=0;
		}
		else{
			ans++;
			h-=x.first;
			Q.pop();
		}
	}
	printf("%d\n",ans);

	return 0;
}
