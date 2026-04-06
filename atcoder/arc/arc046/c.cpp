#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	vector<pair<int,int>> boy(n),girl(m);
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		boy[i]={a,b};
	}
	rep(i,m){
		int c,d; scanf("%d%d",&c,&d);
		girl[i]={d,c};
	}

	sort(boy .begin(),boy .end());
	sort(girl.begin(),girl.end());

	int ans=0;
	multiset<int> S;
	for(int i=0,j=0;i<n;i++){
		while(j<m && girl[j].first<=boy[i].first){
			S.emplace(girl[j].second);
			j++;
		}

		if(S.empty()) continue;

		auto it=S.lower_bound(boy[i].second);
		if(it!=S.end()){
			S.erase(it);
			ans++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
