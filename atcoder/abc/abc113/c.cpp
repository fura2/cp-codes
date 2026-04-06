#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<set<pair<int,int>>> f(n);
	vector<int> p(m);
	rep(i,m){
		int y; scanf("%d%d",&p[i],&y); p[i]--;
		f[p[i]].emplace(y,i);
	}

	vector<int> ans(m);
	rep(q,n){
		int i=0;
		for(auto x:f[q]) ans[x.second]=i++;
	}
	rep(i,m) printf("%06d%06d\n",p[i]+1,ans[i]+1);

	return 0;
}
