#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector<vector<int>> a;
	if(n%2==1){
		rep(i,n/2) a.push_back({i+1,n-i-1});
		a.push_back({n});
	}else{
		rep(i,n/2) a.push_back({i+1,n-i});
	}

	vector<pair<int,int>> E;
	rep(i,a.size()) rep(j,i) {
		for(int u:a[i]) for(int v:a[j]) E.emplace_back(u,v);
	}

	printf("%lu\n",E.size());
	for(auto e:E) printf("%d %d\n",e.first,e.second);

	return 0;
}
