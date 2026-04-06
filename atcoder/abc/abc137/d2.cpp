#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	vector Ev(m,vector<int>());
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		if(a<=m) Ev[m-a].emplace_back(b);
	}

	int ans=0;
	priority_queue<int> Q;
	for(int x=m-1;x>=0;x--){
		for(auto b:Ev[x]) Q.emplace(b);
		if(!Q.empty()){
			ans+=Q.top(); Q.pop();
		}
	}
	printf("%d\n",ans);

	return 0;
}
