#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	set<int> S;
	rep(i,n){
		int a; scanf("%d",&a);
		S.emplace(a);
	}

	while(S.size()>=2){
		int mn=*S.begin();
		while(1){
			int mx=*S.rbegin();
			if(mx==mn) break;
			S.erase(--S.end());
			S.emplace(mx%mn==0?mn:mx%mn);
		}
	}

	printf("%d\n",*S.begin());

	return 0;
}
