#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	vector<int> w(n),v(n),x(m);
	rep(i,n) scanf("%d%d",&w[i],&v[i]);
	rep(j,m) scanf("%d",&x[j]);

	{
		vector<pair<int,int>> p(n);
		rep(i,n) p[i]={w[i],v[i]};
		sort(p.begin(),p.end(),[](auto a,auto b){
			return a.first>b.first;
		});
		rep(i,n) tie(w[i],v[i])=p[i];
	}

	vector<int> pos(m,n);
	rep(j,m){
		rep(i,n) if(w[i]<=x[j]) {
			pos[j]=i;
			break;
		}
	}

	rep(_,q){
		int l,r; scanf("%d%d",&l,&r); l--;

		vector<int> cnt(n+1);
		rep(j,m) if(j<l || r<=j) cnt[pos[j]]++;

		int ans=0;
		multiset<int> V;
		for(int i=n-1;i>=0;i--){
			V.emplace(v[i]);
			rep(_,cnt[i]){
				if(V.empty()) break;
				ans+=*V.rbegin();
				V.erase(prev(V.end()));
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
