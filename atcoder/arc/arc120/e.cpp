#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint lo=0,hi=5e8;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		bool ok=true;
		vector<pair<lint,lint>> P={{mi,mi+a[0]}};
		for(int i=1;i<n;i++){
			vector<pair<lint,lint>> P2;
			for(auto [t,x]:P){
				if(a[i]-t>x) continue;

				P2.emplace_back((t+x-a[i])/2,(t+x+a[i])/2);
				if(t<mi){
					P2.emplace_back(mi,x+mi-t);
				}
			}
			if(P2.empty()){
				ok=false;
				break;
			}

			P.clear();
			rep(j,P2.size()){
				bool ok2=true;
				rep(k,P2.size()) if(k!=j) {
					if(P2[j].second-P2[j].first==P2[k].second-P2[k].first && P2[j].first<P2[k].first){
						ok2=false;
						break;
					}
				}
				if(ok2) P.emplace_back(P2[j]);
			}
		}

		if(ok) hi=mi;
		else   lo=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
