#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int L; cin>>L;

	int n;
	for(n=0;(1<<n)<=L;n++);

	vector<vector<pair<int,int>>> G(n);
	rep(i,n-1){
		G[i].emplace_back(i+1,0);
		G[i].emplace_back(i+1,1<<(n-i-2));
	}
	int sum=1<<(n-1);
	rep(i,n-1) if(L>>(n-i-2)&1) {
		G[0].emplace_back(i+1,sum);
		sum+=1<<(n-i-2);
	}

	int m=0;
	rep(u,n) m+=G[u].size();

	printf("%d %d\n",n,m);
	rep(u,n) for(auto e:G[u]) printf("%d %d %d\n",u+1,e.first+1,e.second);

	return 0;
}
