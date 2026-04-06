#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b,k; scanf("%d%d%d%d",&n,&a,&b,&k);

	set<int> S={a,b};
	rep(i,k){ int p; scanf("%d",&p); S.emplace(p); }
	puts(S.size()==k+2?"YES":"NO");

	return 0;
}
