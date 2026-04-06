#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	int l[41]={},r[41]={};
	rep(i,n){ int a; scanf("%d",&a); l[a]++; }
	rep(j,m){ int a; scanf("%d",&a); r[a]++; }

	int ans=0;
	rep(a,41) ans+=min(l[a],r[a]);
	printf("%d\n",ans);

	return 0;
}
