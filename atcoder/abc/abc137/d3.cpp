// マトロイドに対する貪欲法とみて解く
// https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20121103/1351911603.html

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	vector<pair<int,int>> p(n);
	rep(i,n) scanf("%d%d",&p[i].second,&p[i].first);
	sort(p.rbegin(),p.rend());

	set<int> S;
	rep(x,m) S.emplace(x);

	int ans=0;
	for(auto [b,a]:p){
		auto it=S.upper_bound(m-a);
		if(it!=S.begin()){
			S.erase(--it);
			ans+=b;
		}
	}
	printf("%d\n",ans);

	return 0;
}
