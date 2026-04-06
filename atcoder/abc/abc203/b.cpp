#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) ans+=100*i+j;
	printf("%d\n",ans);
	return 0;
}
