#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<vector<int>> L;

int dfs(int i){
	int m=L[i].size();
	vector<int> dep(m);
	rep(j,m) dep[j]=dfs(L[i][j]);
	sort(dep.rbegin(),dep.rend());

	int res=0;
	rep(j,m) res=max(res,dep[j]+j+1);
	return res;
}

int main(){
	int n; scanf("%d",&n);
	L.resize(n);
	for(int i=1;i<n;i++){
		int a; scanf("%d",&a); a--;
		L[a].emplace_back(i);
	}

	printf("%d\n",dfs(0));

	return 0;
}
