#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int x,y,a,b,c; scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	vector<int> p(a),q(b),r(c);
	rep(i,a) scanf("%d",&p[i]);
	rep(i,b) scanf("%d",&q[i]);
	rep(i,c) scanf("%d",&r[i]);

	sort(p.rbegin(),p.rend());
	sort(q.rbegin(),q.rend());

	rep(i,x) r.emplace_back(p[i]);
	rep(i,y) r.emplace_back(q[i]);
	sort(r.rbegin(),r.rend());

	printf("%lld\n",accumulate(r.begin(),r.begin()+x+y,0LL));

	return 0;
}
