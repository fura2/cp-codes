#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n),pos(n);
	rep(i,n) scanf("%d%d",&a[i],&pos[i]), pos[i]--;

	vector<multiset<int>> S(2e5);
	rep(i,n) S[pos[i]].emplace(a[i]);
	multiset<int> S_max;
	rep(x,2e5) if(!S[x].empty()) S_max.emplace(*S[x].rbegin());

	rep(_,q){
		int i,to; scanf("%d%d",&i,&to); i--; to--;

		S[pos[i]].erase(S[pos[i]].find(a[i]));
		if(S[pos[i]].empty()){
			S_max.erase(S_max.find(a[i]));
		}
		else if(*S[pos[i]].rbegin()<a[i]){
			S_max.erase(S_max.find(a[i]));
			S_max.emplace(*S[pos[i]].rbegin());
		}

		pos[i]=to;
		if(S[pos[i]].empty()){
			S_max.emplace(a[i]);
		}
		else if(*S[pos[i]].rbegin()<a[i]){
			S_max.erase(S_max.find(*S[pos[i]].rbegin()));
			S_max.emplace(a[i]);
		}
		S[pos[i]].emplace(a[i]);

		printf("%d\n",*S_max.begin());
	}

	return 0;
}
