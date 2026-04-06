#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<vector<int>> a(n,vector<int>(n-1));
	rep(u,n){
		rep(i,n-1) scanf("%d",&a[u][i]), a[u][i]--;
		reverse(a[u].begin(),a[u].end());
	}

	queue<pair<int,int>> Q;
	rep(u,n){
		int v=a[u].back();
		if(a[v].back()==u) Q.emplace(u,v);
	}

	int ans=0,cnt=0;
	while(cnt<n){
		vector<int> U; // updated players
		while(!Q.empty()){
			int u=Q.front().first;
			int v=Q.front().second;
			Q.pop();

			if(!a[u].empty() && a[u].back()==v){
				a[u].pop_back();
				a[v].pop_back();
				if(a[u].empty()) cnt++;
				if(a[v].empty()) cnt++;
				U.emplace_back(u);
				U.emplace_back(v);
			}
		}

		if(U.empty()){ puts("-1"); return 0; }

		for(int u:U) if(!a[u].empty()) {
			int v=a[u].back();
			if(a[v].back()==u) Q.emplace(u,v);
		}

		ans++;
	}

	printf("%d\n",ans);

	return 0;
}
