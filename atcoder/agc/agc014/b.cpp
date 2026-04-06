#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);

	vector<int> deg(n);
	rep(_,q){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		deg[u]++;
		deg[v]++;
	}

	bool ok=true;
	rep(u,n) if(deg[u]%2==1) ok=false;
	puts(ok?"YES":"NO");

	return 0;
}
